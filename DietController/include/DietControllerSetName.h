

#ifndef DIETPROJECT_DIETCONTROLLERSETNAME_H
#define DIETPROJECT_DIETCONTROLLERSETNAME_H

#include "DietController.h"

namespace diet {

    class DietControllerSetName : public diet::DietController {
    public:
        void invoke(const std::wstring &params) const override;
    };

} // diet

#endif //DIETPROJECT_DIETCONTROLLERSETNAME_H
