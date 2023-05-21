//
// Created by golov on 20.05.2023.
//

#include "TokenElse.h"

namespace diet {
    TokenElse::TokenElse(const std::string& string) : TemplateToken(string) {}

    TemplateToken::TokenType TokenElse::getType() const {
        return ELSE;
    }

    int TokenElse::getPriority() const {
        return priority_;
    }

    void TokenElse::setPriority(int priority) {
        priority_ = priority;
    }

} // diet