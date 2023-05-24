

#ifndef DIETPROJECT_DIETCONTROLLERSHOWPERIODS_H
#define DIETPROJECT_DIETCONTROLLERSHOWPERIODS_H

#include "DietController.h"

namespace diet {

    class DietControllerShowPeriods : public DietController {
    public:
        void invoke(const std::wstring &params) const override;
    };

} // diet

#endif //DIETPROJECT_DIETCONTROLLERSHOWPERIODS_H
