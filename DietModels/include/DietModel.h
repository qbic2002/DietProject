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
        std::string getField(const std::string& fieldName) const;
    private:
        nlohmann::json jsonData_;
    };

} // diet

#endif //DIETPROJECT_DIETMODEL_H
