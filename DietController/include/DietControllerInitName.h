

#ifndef DIETPROJECT_DIETCONTROLLERINITNAME_H
#define DIETPROJECT_DIETCONTROLLERINITNAME_H

#include "DietController.h"

namespace diet {

    class DietControllerInitName : public diet::DietController {
    public:
        void invoke(const std::wstring &params) const override;
    };

} // diet

#endif //DIETPROJECT_DIETCONTROLLERINITNAME_H
