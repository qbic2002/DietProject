//
// Created by golov on 19.05.2023.
//

#include "DietControllerGreeting.h"
#include "ViewEngine.h"

namespace diet {
    void DietControllerGreeting::invoke(const std::wstring &params) const {
        diet::ViewEngine::render("greeting", {});
    }
} // diet