//
// Created by golov on 20.05.2023.
//

#include "TemplateToken.h"

diet::TemplateToken::TemplateToken(const std::string& string) : string_(string) {}

size_t diet::TemplateToken::getStartPos() const {
    return startPos_;
}

void diet::TemplateToken::setStartPos(size_t startPos) {
    TemplateToken::startPos_ = startPos;
}

size_t diet::TemplateToken::getEndPos() const {
    return endPos_;
}

void diet::TemplateToken::setEndPos(size_t endPos) {
    TemplateToken::endPos_ = endPos;
}

const std::string& diet::TemplateToken::getString() const {
    return string_;
}
