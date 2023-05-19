//
// Created by golov on 19.05.2023.
//

#include "DietModel.h"

namespace diet {
    std::string DietModel::getField(const std::string& fieldName) const {
        std::string value = to_string(jsonData_[fieldName]);
        if (value.starts_with('"') && value.ends_with('"'))
            return {value.begin() + 1, value.end() - 1}; // return string without first and last char
        return value;
    }
} // diet