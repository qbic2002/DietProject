//
// Created by golov on 20.05.2023.
//

#ifndef DIETPROJECT_DIETCONTROLLERSETWEIGHT_H
#define DIETPROJECT_DIETCONTROLLERSETWEIGHT_H

#include "DietController.h"

namespace diet {

    class DietControllerSetWeight : public DietController  {
    public:
        void invoke(const std::wstring &params) const override;
    };

} // diet

#endif //DIETPROJECT_DIETCONTROLLERSETWEIGHT_H
