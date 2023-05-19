//
// Created by golov on 20.05.2023.
//

#ifndef DIETPROJECT_DIETCONTROLLERINITWEIGHT_H
#define DIETPROJECT_DIETCONTROLLERINITWEIGHT_H

#include "DietController.h"

namespace diet {
    class DietControllerInitWeight : public DietController {
    public:
        void invoke(const std::string& params) const override;
    };
}


#endif //DIETPROJECT_DIETCONTROLLERINITWEIGHT_H
