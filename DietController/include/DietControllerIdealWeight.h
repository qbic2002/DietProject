//
// Created by golov on 20.05.2023.
//

#ifndef DIETPROJECT_DIETCONTROLLERIDEALWEIGHT_H
#define DIETPROJECT_DIETCONTROLLERIDEALWEIGHT_H

#include "DietController.h"

namespace diet {

    class DietControllerIdealWeight : public DietController {
    public:
        void invoke(const std::wstring &params) const override;
    };

} // diet

#endif //DIETPROJECT_DIETCONTROLLERIDEALWEIGHT_H
