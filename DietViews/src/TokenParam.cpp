

#include "TokenParam.h"

namespace diet {
    TokenParam::TokenParam(const std::wstring& string) : TemplateToken(string) {}

    TemplateToken::TokenType TokenParam::getType() const {
        return PARAM;
    }

    std::wstring TokenParam::getParamName() const {
        return string_.substr(2, string_.length() - 4);
    }

}