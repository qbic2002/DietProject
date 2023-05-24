//
// Created by msi on 24.05.2023.
//

#ifndef DIETPROJECT_DIETCONTROLLERCONFIRMDIET_H
#define DIETPROJECT_DIETCONTROLLERCONFIRMDIET_H

#include "DietController.h"

namespace diet {

    class DietControllerConfirmDiet : public DietController {
    public:
        void invoke(const std::wstring &params) const override;
    };

} // diet

#endif //DIETPROJECT_DIETCONTROLLERCONFIRMDIET_H
