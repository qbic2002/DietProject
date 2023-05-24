//
// Created by golov on 20.05.2023.
//

#include "TokenContent.h"

namespace diet {
    TokenContent::TokenContent(const std::wstring& content) : TemplateToken(content) {}


    TemplateToken::TokenType TokenContent::getType() const {
        return CONTENT;
    }

} // diet