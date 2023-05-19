//
// Created by golov on 20.05.2023.
//

#ifndef DIETPROJECT_DIETCONTROLLERSETHEIGHT_H
#define DIETPROJECT_DIETCONTROLLERSETHEIGHT_H

#include "DietController.h"

namespace diet {

    class DietControllerSetHeight : public DietController {
    public:
        void invoke(const std::string& params) const override;
    };

} // diet

#endif //DIETPROJECT_DIETCONTROLLERSETHEIGHT_H
