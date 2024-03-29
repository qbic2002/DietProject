

#ifndef DIETPROJECT_DIETCONTROLLERSETHEIGHT_H
#define DIETPROJECT_DIETCONTROLLERSETHEIGHT_H

#include "DietController.h"

namespace diet {

    class DietControllerSetHeight : public DietController {
    public:
        void invoke(const std::wstring &params) const override;
    };

} // diet

#endif //DIETPROJECT_DIETCONTROLLERSETHEIGHT_H
