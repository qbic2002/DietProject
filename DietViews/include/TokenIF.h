

#ifndef DIETPROJECT_TOKENIF_H
#define DIETPROJECT_TOKENIF_H

#include <string>
#include "TemplateToken.h"

namespace diet {

    class TokenIF : public TemplateToken {
    public:
        explicit TokenIF(const std::wstring& string);

        TokenType getType() const override;

        std::wstring getParamName() const; // имя шаблонного параметра

        int getPriority() const;
        void setPriority(int priority);

    private:
        int priority_ = 0; // приоритет if
    };

} // diet

#endif //DIETPROJECT_TOKENIF_H
