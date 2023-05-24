//
// Created by msi on 24.05.2023.
//

#ifndef DIETPROJECT_DIETCONTROLLERSHOWDIETS_H
#define DIETPROJECT_DIETCONTROLLERSHOWDIETS_H

#include "DietController.h"

namespace diet {

    class DietControllerShowDiets : public DietController {
    public:
        void invoke(const std::wstring &params) const override;
    };

} // diet

#endif //DIETPROJECT_DIETCONTROLLERSHOWDIETS_H
