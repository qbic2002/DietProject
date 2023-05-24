//
// Created by golov on 19.05.2023.
//

#include "DietModel.h"
#include "FileUtils.h"

namespace diet {
    std::wstring DietModel::getField(const std::wstring& fieldName) const {
        std::string value = to_string((jsonData_[utils::to_string(fieldName)]));

        std::wstring wValue = utils::to_wstring(value);
        if (wValue.starts_with(L'"') && wValue.ends_with(L'"'))
            return {wValue.begin() + 1, wValue.end() - 1}; // return string without first and last char
        return wValue;
    }
} // diet