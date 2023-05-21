//
// Created by golov on 21.05.2023.
//

#include "TokenParam.h"

namespace diet {
    TokenParam::TokenParam(const std::string& string) : TemplateToken(string) {}

    TemplateToken::TokenType TokenParam::getType() const {
        return PARAM;
    }

    std::string TokenParam::getParamName() const {
        return string_.substr(2, string_.length() - 4);
    }

}