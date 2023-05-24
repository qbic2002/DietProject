

#include "TokenCloseIF.h"

namespace diet {
    TokenCloseIF::TokenCloseIF(const std::wstring& string) : TemplateToken(string) {}


    TemplateToken::TokenType TokenCloseIF::getType() const {
        return CLOSE_IF;
    }

    int TokenCloseIF::getPriority() const {
        return priority;
    }
    void TokenCloseIF::setPriority(int priority) {
        TokenCloseIF::priority = priority;
    }

} // diet