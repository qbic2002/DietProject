//
// Created by golov on 21.05.2023.
//

#include "TokenController.h"

namespace diet {
    TokenController::TokenController(const std::string& string) : TemplateToken(string) {}

    TemplateToken::TokenType TokenController::getType() const {
        return CONTROLLER;
    }

    std::string TokenController::getControllerName() const {
        if (string_.ends_with('$')){
            return string_.substr(2, string_.length() - 3);
        }
        return string_.substr(2, string_.length() - 2);
    }

    bool TokenController::getAnyKey() const {
        if (string_.ends_with('$')){
            return true;
        }
        return false;
    }
} // diet