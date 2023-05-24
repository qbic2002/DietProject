

#ifndef DIETPROJECT_TOKENCONTAINER_H
#define DIETPROJECT_TOKENCONTAINER_H

#include <vector>
#include "TemplateToken.h"

namespace diet {

    class TokenContainer {
    public:
        using vectorType = std::vector<diet::TemplateToken*>;

        TokenContainer() = default;
        TokenContainer(const TokenContainer& other) = delete;
        TokenContainer(TokenContainer&& other) noexcept = delete;
        TokenContainer& operator=(const TokenContainer& other) = delete;

        void push_back(vectorType::value_type& value);
        vectorType::iterator erase(const TokenContainer::vectorType::iterator& b, const TokenContainer::vectorType::iterator& end);
        vectorType::value_type& operator[](std::size_t n);
        std::size_t size();

        vectorType::const_iterator cbegin();
        vectorType::iterator begin();
        vectorType::iterator end();

        TokenContainer::vectorType::iterator insert(const TokenContainer::vectorType::const_iterator& it, TemplateToken*&& value);

        ~TokenContainer();
    private:
        vectorType vector_;
    };

} // diet

#endif //DIETPROJECT_TOKENCONTAINER_H
