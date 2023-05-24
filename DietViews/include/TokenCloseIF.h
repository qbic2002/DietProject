

#ifndef DIETPROJECT_TOKENCLOSEIF_H
#define DIETPROJECT_TOKENCLOSEIF_H

#include "TemplateToken.h"

namespace diet {

    class TokenCloseIF : public TemplateToken {
    public:
        explicit TokenCloseIF(const std::wstring& string);

        TokenType getType() const override;

        int getPriority() const;
        void setPriority(int priority);

    private:
        int priority = 0; // приоритет if
    };

} // diet

#endif //DIETPROJECT_TOKENCLOSEIF_H
