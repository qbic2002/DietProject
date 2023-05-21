//
// Created by golov on 21.05.2023.
//

#include "DietControllerInitName.h"
#include "ViewEngine.h"

namespace diet {
    void DietControllerInitName::invoke(const std::string& params) const {
        diet::ViewEngine::render("initName", {});
    }
} // diet