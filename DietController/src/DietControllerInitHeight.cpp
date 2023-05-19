//
// Created by golov on 19.05.2023.
//

#include "DietControllerInitHeight.h"
#include "ViewEngine.h"

namespace diet {
    void DietControllerInitHeight::invoke(const std::string& params) const {
        diet::ViewEngine::render("initHeight", {});
    }
} // diet