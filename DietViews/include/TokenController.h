//
// Created by golov on 21.05.2023.
//

#ifndef DIETPROJECT_TOKENCONTROLLER_H
#define DIETPROJECT_TOKENCONTROLLER_H

#include "TemplateToken.h"

namespace diet {

    class TokenController : public diet::TemplateToken {
    public:
        explicit TokenController(const std::string& string);
        TokenType getType() const override;
        std::string getControllerName() const;
        bool getAnyKey() const;
    };

} // diet

#endif //DIETPROJECT_TOKENCONTROLLER_H
