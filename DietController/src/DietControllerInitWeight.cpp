//
// Created by golov on 20.05.2023.
//

#include "DietControllerInitWeight.h"
#include "ViewEngine.h"

namespace diet{

    void DietControllerInitWeight::invoke(const std::wstring &params) const {
        diet::ViewEngine::render("initWeight", {});
    }
}