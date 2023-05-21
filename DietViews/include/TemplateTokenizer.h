//
// Created by golov on 20.05.2023.
//

#ifndef DIETPROJECT_TEMPLATETOKENIZER_H
#define DIETPROJECT_TEMPLATETOKENIZER_H

#include "TemplateToken.h"
#include "TokenContainer.h"
#include <vector>

namespace diet {

    class TemplateTokenizer {
    public:
        static void tokenize(const std::string& input, diet::TokenContainer & tokens);
    };

}


#endif //DIETPROJECT_TEMPLATETOKENIZER_H
