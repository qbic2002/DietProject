

#ifndef DIETPROJECT_DIETCONTROLLERRETURNTODIETS_H
#define DIETPROJECT_DIETCONTROLLERRETURNTODIETS_H

#include "DietController.h"

namespace diet {

    class DietControllerReturnToDiets : public DietController {
    public:
        void invoke(const std::wstring& params) const override;
    };

} // diet

#endif //DIETPROJECT_DIETCONTROLLERRETURNTODIETS_H
