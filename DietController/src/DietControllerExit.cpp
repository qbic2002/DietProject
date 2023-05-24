

#include "DietControllerExit.h"

namespace diet {
    void DietControllerExit::invoke(const std::wstring &params) const {
        exit(0);
    }
} // diet