//
// Created by golov on 19.05.2023.
//

#include <iostream>
#include "ViewEngine.h"
#include "FileUtils.h"
#include "DietApp.h"
#include "TemplateToken.h"
#include "TemplateTokenizer.h"
#include "TokenParam.h"
#include "TokenContent.h"
#include "TokenIF.h"
#include "TokenElse.h"
#include "TokenCloseIF.h"
#include "TokenController.h"

namespace diet {
    void ViewEngine::render(const std::string& viewName, const DietModel& model) {
        diet::DietApp::getInstance()->getConsoleInputManager()->setLastViewName(viewName);
        diet::DietApp::getInstance()->getConsoleInputManager()->setLastModel(model);

        std::string templateString = utils::readFile(diet::DietApp::getInstance()->findView(viewName).string());
        std::vector<diet::TemplateToken*> tokens; // TODO RAII Token Container
        try {
            diet::TemplateTokenizer::tokenize(templateString, tokens);
        } catch (...) {
            for (auto& token: tokens) {
                delete token;
                token = nullptr;
            }

            throw;
        }
        std::string renderString = parseTemplate(tokens, model);

        clearConsole();
        std::cout << renderString;
    }

    std::string ViewEngine::parseTemplate(std::vector<diet::TemplateToken*>& tokens, const DietModel& model) {
        parseParamTokens(tokens, model);
        parseIf(tokens, model);

        if (tokens[tokens.size() - 1]->getType() != TemplateToken::TokenType::CONTROLLER) {
            throw std::runtime_error("incorrect template");
        }

        auto controllerToken = (diet::TokenController*)tokens[tokens.size() - 1];

        bool anyKey = controllerToken->getAnyKey();
        std::string controllerName = controllerToken->getControllerName();

        diet::DietApp::getInstance()->getConsoleInputManager()->setAnyKey(anyKey);
        diet::DietApp::getInstance()->getConsoleInputManager()->setControllerName(controllerName);

        std::string renderString;
        for (auto& token: tokens) {
            if (token->getType() != TemplateToken::TokenType::CONTROLLER) {
                renderString.append(token->getString());
            }
            delete token;
            token = nullptr;
        }

        return renderString;
    }
    void ViewEngine::parseParamTokens(std::vector<diet::TemplateToken*>& tokens, const DietModel& model) {
        for (auto& token : tokens) {
            if (token->getType() == TemplateToken::TokenType::PARAM) {
                auto paramToken = (diet::TokenParam*)token;
                std::string value = model.getField(paramToken->getParamName());
                delete token;
                token = new diet::TokenContent(value);
            }
        }
    }

    void ViewEngine::parseIf(std::vector<diet::TemplateToken*>& tokens, const DietModel& model) {
        int priority = 0;
        for (auto& token : tokens) {
            if (token->getType() == TemplateToken::TokenType::IF) {
                auto ifToken = (diet::TokenIF*)token;
                ifToken->setPriority(priority++);
            }
            if (token->getType() == TemplateToken::TokenType::ELSE) {
                auto elseToken = (diet::TokenElse*)token;
                elseToken->setPriority(priority);
            }
            if (token->getType() == TemplateToken::TokenType::CLOSE_IF) {
                auto closeIfToken = (diet::TokenCloseIF*)token;
                closeIfToken->setPriority(priority--);
                if (priority < 0) {
                    throw std::runtime_error("incorrect template");
                }
            }
        }

        if (priority != 0) {
            throw std::runtime_error("incorrect template");
        }

        while (true) {
            int maxInd = -1;
            int maxPriority = -1;

            for (int i = 0; i < tokens.size(); ++i) {
                auto token = tokens[i];
                if (token->getType() == TemplateToken::TokenType::IF) {
                    auto ifToken = (diet::TokenIF*) token;
                    int currentPriority = ifToken->getPriority();
                    if (currentPriority > maxPriority) {
                        maxPriority = currentPriority;
                        maxInd = i;
                    }
                }
            }

            if (maxPriority == -1) {
                break;
            }

            auto ifToken = (diet::TokenIF*)tokens[maxInd];
            std::string value = model.getField(ifToken->getParamName());
            int elseInd = -1;
            for (int i = maxInd; i < tokens.size(); ++i) {
                auto token = tokens[i];
                if (token->getType() == TemplateToken::TokenType::ELSE) {
                    auto elseToken = (diet::TokenElse*)token;
                    if (elseToken->getPriority() == maxPriority) {
                        elseInd = i;
                        break;
                    }
                }
            }
            int closeIfInd = -1;
            for (int i = maxInd; i < tokens.size(); ++i) {
                auto token = tokens[i];
                if (token->getType() == TemplateToken::TokenType::CLOSE_IF) {
                    auto closeIfToken = (diet::TokenCloseIF*)token;
                    closeIfToken->setPriority(priority--);
                    if (closeIfToken->getPriority() == maxPriority) {
                        closeIfInd = i;
                        break;
                    }
                }
            }

            if (closeIfInd == -1) {
                throw std::runtime_error("incorrect template");
            }

            std::string replaceString;
            if (value == "true") {
                if (elseInd == -1) {
                    for (int i = maxInd + 1; i < closeIfInd; ++i) {
                        replaceString.append(tokens[i]->getString());
                    }
                }
                if (elseInd != -1) {
                    for (int i = maxInd + 1; i < elseInd; ++i) {
                        replaceString.append(tokens[i]->getString());
                    }
                }
            }
            if (value == "false") {
                if (elseInd != -1) {
                    for (int i = elseInd + 1; i < closeIfInd; ++i) {
                        replaceString.append(tokens[i]->getString());
                    }
                }
            }

            for (int i = maxInd; i <= closeIfInd; ++i) {
                delete tokens[i];
                tokens[i] = nullptr;
            }

            tokens.erase(tokens.cbegin() + maxInd, tokens.cbegin() + closeIfInd + 1);
            tokens.insert(tokens.cbegin() + maxInd, new diet::TokenContent(replaceString));
        }
    }

    void ViewEngine::clearConsole() {
        system("cls");
    }
} // diet