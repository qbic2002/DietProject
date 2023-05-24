//
// Created by golov on 19.05.2023.
//

#ifndef DIETPROJECT_DIETCONTROLLERINITHEIGHT_H
#define DIETPROJECT_DIETCONTROLLERINITHEIGHT_H

#include "DietController.h"

namespace diet {

    class DietControllerInitHeight : public DietController {
    public:
        void invoke(const std::wstring &params) const override;
    };

} // diet

#endif //DIETPROJECT_DIETCONTROLLERINITHEIGHT_H
