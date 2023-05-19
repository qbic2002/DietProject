//
// Created by golov on 19.05.2023.
//

#ifndef DIETPROJECT_DIETCONTROLLERGREETING_H
#define DIETPROJECT_DIETCONTROLLERGREETING_H

#include "DietController.h"

namespace diet {

    class DietControllerGreeting : public DietController{
    public:
        void invoke(const std::string& params) const override;
    };

} // diet

#endif //DIETPROJECT_DIETCONTROLLERGREETING_H
