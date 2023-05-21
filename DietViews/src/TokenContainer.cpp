//
// Created by golov on 21.05.2023.
//

#include "TokenContainer.h"

namespace diet {
    void TokenContainer::push_back(vectorType::value_type& value) {
        vector_.push_back(value);
    }

    TokenContainer::vectorType::iterator TokenContainer::erase(const TokenContainer::vectorType::iterator& b,
                                                               const TokenContainer::vectorType::iterator& end) {
        for (auto token = b; token != end; ++token) {
            delete *token;
            *token = nullptr;
        }
        return vector_.erase(b, end);
    }

    TokenContainer::vectorType::value_type& TokenContainer::operator[](std::size_t n) {
        return vector_[n];
    }

    std::size_t TokenContainer::size() {
        return vector_.size();
    }

    TokenContainer::vectorType::const_iterator TokenContainer::cbegin() {
        return vector_.cbegin();
    }

    TokenContainer::vectorType::iterator TokenContainer::begin() {
        return vector_.begin();
    }

    TokenContainer::vectorType::iterator
    TokenContainer::insert(const TokenContainer::vectorType::const_iterator& it, TemplateToken*&& value) {
        return vector_.insert(it, value);
    }

    TokenContainer::vectorType::iterator TokenContainer::end() {
        return vector_.end();
    }

    TokenContainer::~TokenContainer() {
        for (auto& token : vector_) {
            delete token;
            token = nullptr;
        }
    }
} // diet