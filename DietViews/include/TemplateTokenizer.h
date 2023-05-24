

#ifndef DIETPROJECT_TEMPLATETOKENIZER_H
#define DIETPROJECT_TEMPLATETOKENIZER_H

#include "TemplateToken.h"
#include "TokenContainer.h"
#include <vector>

namespace diet {

    class TemplateTokenizer {
    public:
        static void tokenize(const std::wstring& input, diet::TokenContainer& tokens); // токенизация строки
    };

}


#endif //DIETPROJECT_TEMPLATETOKENIZER_H
