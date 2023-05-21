//
// Created by golov on 21.05.2023.
//

#ifndef DIETPROJECT_DIETCONTROLLERSETNAME_H
#define DIETPROJECT_DIETCONTROLLERSETNAME_H

#include "DietController.h"

namespace diet {

    class DietControllerSetName : public diet::DietController {
    public:
        void invoke(const std::string& params) const override;
    };

} // diet

#endif //DIETPROJECT_DIETCONTROLLERSETNAME_H
