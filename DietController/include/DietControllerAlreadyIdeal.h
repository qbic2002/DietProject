//
// Created by golov on 24.05.2023.
//

#ifndef DIETPROJECT_DIETCONTROLLERALREADYIDEAL_H
#define DIETPROJECT_DIETCONTROLLERALREADYIDEAL_H

#include "DietController.h"

namespace diet {

    class DietControllerAlreadyIdeal : public DietController {
    public:
        void invoke(const std::wstring& params) const override;
    };

} // diet

#endif //DIETPROJECT_DIETCONTROLLERALREADYIDEAL_H
