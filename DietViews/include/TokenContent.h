

#ifndef DIETPROJECT_TOKENCONTENT_H
#define DIETPROJECT_TOKENCONTENT_H

#include <string>
#include "TemplateToken.h"

namespace diet {

    class TokenContent : public TemplateToken {
    public:
        explicit TokenContent(const std::wstring& content);

        TokenType getType() const override;

    };

} // diet

#endif //DIETPROJECT_TOKENCONTENT_H
