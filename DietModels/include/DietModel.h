//
// Created by golov on 19.05.2023.
//

#ifndef DIETPROJECT_DIETMODEL_H
#define DIETPROJECT_DIETMODEL_H

#include <string>
#include "json.h"

namespace diet {

    class DietModel {
    public:
        std::wstring getField(const std::wstring& fieldName) const;

        template<class T>
        void setField(const std::wstring& fieldName, const T& value) {
            std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;
            if (std::is_same<T, std::wstring>::value) {
                jsonData_[converter.to_bytes(fieldName)] = converter.to_bytes(value);
            } else {
                jsonData_[converter.to_bytes(fieldName)] = value;
            }
        }

    private:
        nlohmann::json jsonData_{};
    };

} // diet

#endif //DIETPROJECT_DIETMODEL_H
