//
// Created by golov on 20.05.2023.
//

#include "TokenContent.h"

namespace diet {
    TokenContent::TokenContent(const std::string& content) : TemplateToken(content) {}

    const std::string& TokenContent::getContent() const {
        return string_;
    }

    TemplateToken::TokenType TokenContent::getType() const {
        return CONTENT;
    }

} // diet