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
#include "TokenContainer.h"

namespace diet {
    void ViewEngine::render(const std::string& viewName, const DietModel& model) {
        diet::DietApp::getInstance()->getConsoleInputManager()->setLastViewName(viewName);
        diet::DietApp::getInstance()->getConsoleInputManager()->setLastModel(model);

        std::wstring templateString = utils::readFile(diet::DietApp::getInstance()->findView(viewName).string());
        diet::TokenContainer tokens;
        diet::TemplateTokenizer::tokenize(templateString, tokens);

        std::wstring renderString = parseTemplate(tokens, model);

        clearConsole();
        std::wcout << renderString;
    }

    std::wstring ViewEngine::parseTemplate(diet::TokenContainer& tokens, const DietModel& model) {
        parseParamTokens(tokens, model);
        parseIf(tokens, model);

        if (tokens[tokens.size() - 1]->getType() != TemplateToken::TokenType::CONTROLLER) {
            throw std::runtime_error("incorrect template");
        }

        auto controllerToken = (diet::TokenController*) tokens[tokens.size() - 1];

        bool anyKey = controllerToken->getAnyKey();
        std::wstring controllerName = controllerToken->getControllerName();

        diet::DietApp::getInstance()->getConsoleInputManager()->setAnyKey(anyKey);
        diet::DietApp::getInstance()->getConsoleInputManager()->setControllerName(utils::to_string(controllerName));

        std::wstring renderString;
        for (auto& token: tokens) {
            if (token->getType() != TemplateToken::TokenType::CONTROLLER) {
                renderString.append(token->getString());
            }
        }

        return renderString;
    }

    void ViewEngine::parseParamTokens(diet::TokenContainer& tokens, const DietModel& model) {
        for (auto& token: tokens) {
            if (token->getType() == TemplateToken::TokenType::PARAM) {
                auto paramToken = (diet::TokenParam*) token;
                std::wstring value = model.getField(paramToken->getParamName());
                delete token;
                token = new diet::TokenContent(value);
            }
        }
    }

    void ViewEngine::parseIf(diet::TokenContainer& tokens, const DietModel& model) {
        int priority = 0;
        for (auto& token: tokens) {
            if (token->getType() == TemplateToken::TokenType::IF) {
                auto ifToken = (diet::TokenIF*) token;
                ifToken->setPriority(++priority);
            }
            if (token->getType() == TemplateToken::TokenType::ELSE) {
                auto elseToken = (diet::TokenElse*) token;
                elseToken->setPriority(priority);
            }
            if (token->getType() == TemplateToken::TokenType::CLOSE_IF) {
                auto closeIfToken = (diet::TokenCloseIF*) token;
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

            auto ifToken = (diet::TokenIF*) tokens[maxInd];
            std::wstring value = model.getField(ifToken->getParamName());
            int elseInd = -1;
            for (int i = maxInd; i < tokens.size(); ++i) {
                auto token = tokens[i];
                if (token->getType() == TemplateToken::TokenType::ELSE) {
                    auto elseToken = (diet::TokenElse*) token;
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
                    auto closeIfToken = (diet::TokenCloseIF*) token;
                    if (closeIfToken->getPriority() == maxPriority) {
                        closeIfInd = i;
                        break;
                    }
                }
            }

            if (closeIfInd == -1) {
                throw std::runtime_error("incorrect template");
            }

            std::wstring replaceString;
            if (value == L"true") {
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
            if (value == L"false") {
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

            tokens.erase(tokens.begin() + maxInd, tokens.begin() + closeIfInd + 1);
            tokens.insert(tokens.begin() + maxInd, new diet::TokenContent(replaceString));
        }
    }

    void ViewEngine::clearConsole() {
        system("cls");
    }
} // diet