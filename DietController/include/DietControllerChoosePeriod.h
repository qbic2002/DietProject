//
// Created by golov on 24.05.2023.
//

#ifndef DIETPROJECT_DIETCONTROLLERCHOOSEPERIOD_H
#define DIETPROJECT_DIETCONTROLLERCHOOSEPERIOD_H

#include "DietController.h"

namespace diet {

    class DietControllerChoosePeriod : public DietController {
    public:
        void invoke(const std::wstring& params) const override;
    };

} // diet

#endif //DIETPROJECT_DIETCONTROLLERCHOOSEPERIOD_H
