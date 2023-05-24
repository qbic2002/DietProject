//
// Created by golov on 20.05.2023.
//

#include "TokenIF.h"

namespace diet {
    TokenIF::TokenIF(const std::wstring& string) : TemplateToken(string) {}

    TemplateToken::TokenType TokenIF::getType() const {
        return IF;
    }

    std::wstring TokenIF::getParamName() const {
        return string_.substr(2, string_.length() - 4);
    }

    int TokenIF::getPriority() const {
        return priority_;
    }

    void TokenIF::setPriority(int priority) {
        priority_ = priority;
    }

} // diet