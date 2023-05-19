//
// Created by golov on 19.05.2023.
//

#include "DietControllerExit.h"

namespace diet {
    void DietControllerExit::invoke(const std::string& params) const {
        exit(0);
    }
} // diet