//
// Created by golov on 21.05.2023.
//

#ifndef DIETPROJECT_DIETCONTROLLERINITNAME_H
#define DIETPROJECT_DIETCONTROLLERINITNAME_H

#include "DietController.h"

namespace diet {

    class DietControllerInitName : public diet::DietController {
    public:
        void invoke(const std::string& params) const override;
    };

} // diet

#endif //DIETPROJECT_DIETCONTROLLERINITNAME_H