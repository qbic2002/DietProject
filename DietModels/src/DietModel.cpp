//
// Created by golov on 19.05.2023.
//

#include "DietModel.h"

namespace diet {
    std::string DietModel::getField(const std::string& fieldName) const {
        std::string strWithQuotes = jsonData_[fieldName];
        return {strWithQuotes.begin() + 1, strWithQuotes.end() - 1}; // return string without first and last char
    }
} // diet