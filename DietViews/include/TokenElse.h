

#ifndef DIETPROJECT_TOKENELSE_H
#define DIETPROJECT_TOKENELSE_H

#include "TemplateToken.h"

namespace diet {

    class TokenElse : public TemplateToken {
    public:
        explicit TokenElse(const std::wstring& string);

        TokenType getType() const override;

        int getPriority() const;
        void setPriority(int priority);

    private:
        int priority_ = 0; // приоритет if
    };

} // diet

#endif //DIETPROJECT_TOKENELSE_H
