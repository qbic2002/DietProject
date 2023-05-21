//
// Created by golov on 20.05.2023.
//

#ifndef DIETPROJECT_TOKENCLOSEIF_H
#define DIETPROJECT_TOKENCLOSEIF_H

#include "TemplateToken.h"

namespace diet {

    class TokenCloseIF : public TemplateToken {
    public:
        explicit TokenCloseIF(const std::string& string);

        TokenType getType() const override;

        int getPriority() const;
        void setPriority(int priority);

    private:
        int priority = 0;
    };

} // diet

#endif //DIETPROJECT_TOKENCLOSEIF_H
