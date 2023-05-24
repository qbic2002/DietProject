//
// Created by golov on 19.05.2023.
//

#ifndef DIETPROJECT_DIETMODEL_H
#define DIETPROJECT_DIETMODEL_H

#include <string>
#include "json.h"
#include "FileUtils.h"

namespace diet {

    class DietModel {
    public:
        std::wstring getField(const std::wstring& fieldName) const;

        template<class T>
        void setField(const std::wstring& fieldName, const T& value) {
            jsonData_[utils::to_string(fieldName)] = value;
        }

        void setField(const std::wstring& fieldName, const std::wstring& value) {
            jsonData_[utils::to_string(fieldName)] = utils::to_string(value);
        }

    private:
        nlohmann::json jsonData_{};
    };

} // diet

#endif //DIETPROJECT_DIETMODEL_H
