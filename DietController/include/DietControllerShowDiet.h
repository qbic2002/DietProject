//
// Created by msi on 24.05.2023.
//

#ifndef DIETPROJECT_DIETCONTROLLERSHOWDIET_H
#define DIETPROJECT_DIETCONTROLLERSHOWDIET_H

#include "DietController.h"

namespace diet {

    class DietControllerShowDiet : public DietController{
    public:
        void invoke(const std::wstring &params) const override;
    };

} // diet

#endif //DIETPROJECT_DIETCONTROLLERSHOWDIET_H
