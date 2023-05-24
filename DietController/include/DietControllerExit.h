//
// Created by golov on 19.05.2023.
//

#ifndef DIETPROJECT_DIETCONTROLLEREXIT_H
#define DIETPROJECT_DIETCONTROLLEREXIT_H

#include "DietController.h"

namespace diet {

    class DietControllerExit : public diet::DietController {
    public:
        void invoke(const std::wstring &params) const override;
    };

} // diet

#endif //DIETPROJECT_DIETCONTROLLEREXIT_H
