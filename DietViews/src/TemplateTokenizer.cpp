//
// Created by golov on 20.05.2023.
//

#include <stdexcept>
#include <algorithm>
#include "TemplateTokenizer.h"
#include "TokenContent.h"
#include "TokenIF.h"
#include "TokenElse.h"
#include "TokenCloseIF.h"
#include "TokenParam.h"
#include "TokenController.h"

namespace diet {

    void TemplateTokenizer::tokenize(const std::string& input, diet::TokenContainer& tokens) {
        std::size_t pos = 0;
        while (true) {
            pos = input.find("{#", pos);
            if (pos == std::string::npos) {
                break;
            }
            std::size_t closingPos = input.find("#}", pos);
            if (closingPos == std::string::npos) {
                throw std::runtime_error("incorrect template");
            }

            diet::TemplateToken* ifToken = new diet::TokenIF(input.substr(pos, closingPos + 2 - pos));
            ifToken->setStartPos(pos);
            ifToken->setEndPos(closingPos + 2);
            tokens.push_back(ifToken);
            pos = closingPos;
        }

        pos = 0;
        while (true) {
            pos = input.find("{!!}", pos);
            if (pos == std::string::npos) {
                break;
            }

            diet::TemplateToken* elseToken = new diet::TokenElse("{!!}");
            elseToken->setStartPos(pos);
            elseToken->setEndPos(pos + 4);
            tokens.push_back(elseToken);
            ++pos;
        }

        pos = 0;
        while (true) {
            pos = input.find("{//}", pos);
            if (pos == std::string::npos) {
                break;
            }

            diet::TemplateToken* closeIfToken = new diet::TokenCloseIF("{//}");
            closeIfToken->setStartPos(pos);
            closeIfToken->setEndPos(pos + 4);
            tokens.push_back(closeIfToken);
            ++pos;
        }

        pos = 0;
        while (true) {
            pos = input.find("{{", pos);
            if (pos == std::string::npos) {
                break;
            }
            std::size_t closingPos = input.find("}}", pos);
            if (closingPos == std::string::npos) {
                throw std::runtime_error("incorrect template");
            }

            diet::TemplateToken* paramToken = new diet::TokenParam(input.substr(pos, closingPos + 2 - pos));
            paramToken->setStartPos(pos);
            paramToken->setEndPos(closingPos + 2);
            tokens.push_back(paramToken);
            pos = closingPos;
        }

        pos = 0;

        {
            pos = input.find("\n$", pos);
            if (pos == std::string::npos) {
                throw std::runtime_error("incorrect template. Miss next controller");
            }
            diet::TemplateToken* controllerToken = new diet::TokenController(input.substr(pos, input.length() - pos));
            controllerToken->setStartPos(pos);
            controllerToken->setEndPos(input.length());
            tokens.push_back(controllerToken);
        }

        std::sort(tokens.begin(), tokens.end(), [](const diet::TemplateToken* a, const diet::TemplateToken* b) {
            return a->getStartPos() < b->getStartPos();
        });

        std::size_t tokensSize = tokens.size();
        if (tokensSize == 0) {
            diet::TemplateToken* contentToken = new diet::TokenContent(input);

            contentToken->setStartPos(0);
            contentToken->setEndPos(input.length());
            tokens.push_back(contentToken);

            return;
        }
        diet::TemplateToken* startContentToken = new diet::TokenContent(input.substr(0, tokens[0]->getStartPos() - 0));

        startContentToken->setStartPos(0);
        startContentToken->setEndPos(tokens[0]->getStartPos());
        tokens.push_back(startContentToken);

        for (int i = 0; i < tokensSize - 1; ++i) {
            diet::TemplateToken* contentToken = new diet::TokenContent(
                    input.substr(tokens[i]->getEndPos(), tokens[i + 1]->getStartPos() - tokens[i]->getEndPos()));

            contentToken->setStartPos(tokens[i]->getEndPos());
            contentToken->setEndPos(tokens[i + 1]->getStartPos());
            tokens.push_back(contentToken);
        }
        std::sort(tokens.begin(), tokens.end(), [](const diet::TemplateToken* a, const diet::TemplateToken* b) {
            return a->getStartPos() < b->getStartPos();
        });
    }
}