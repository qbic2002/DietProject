

#ifndef DIETPROJECT_DIETMODEL_H
#define DIETPROJECT_DIETMODEL_H

#include <string>
#include "json.h"
#include "FileUtils.h"

namespace diet {

    class DietModel {
    public:
        std::wstring getField(const std::wstring& fieldName) const; // получение поля из модели данных

        template<class T>
        void setField(const std::wstring& fieldName, const T& value) { // запись в модель данных
            jsonData_[utils::to_string(fieldName)] = value;
        }

        void setField(const std::wstring& fieldName, const std::wstring& value) { // запись в модель данных, если поле wstring
            jsonData_[utils::to_string(fieldName)] = utils::to_string(value);
        }

    private:
        nlohmann::json jsonData_{}; // сам объект json
    };

} // diet

#endif //DIETPROJECT_DIETMODEL_H
