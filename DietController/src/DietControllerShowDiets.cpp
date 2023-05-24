//
// Created by msi on 24.05.2023.
//

#include "DietControllerShowDiets.h"
#include "ViewEngine.h"

namespace diet {
    void DietControllerShowDiets::invoke(const std::wstring &params) const {
        diet::ViewEngine::render("chooseDiet", {});
    }
} // diet