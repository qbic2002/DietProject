

#ifndef DIETPROJECT_DIETCONTROLLERCHOOSEDIET_H
#define DIETPROJECT_DIETCONTROLLERCHOOSEDIET_H

#include "DietController.h"

namespace diet {

    class DietControllerChooseDiet : public DietController {
    public:
        void invoke(const std::wstring &params) const override;
    };

} // diet

#endif //DIETPROJECT_DIETCONTROLLERCHOOSEDIET_H
