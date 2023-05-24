

#ifndef DIETPROJECT_TOKENPARAM_H
#define DIETPROJECT_TOKENPARAM_H

#include "TemplateToken.h"

namespace diet {
    class TokenParam : public diet::TemplateToken {
    public:
        explicit TokenParam(const std::wstring& string);

        TokenType getType() const override;
        std::wstring getParamName() const; // имя шаблонного параметра
    };
}


#endif //DIETPROJECT_TOKENPARAM_H
