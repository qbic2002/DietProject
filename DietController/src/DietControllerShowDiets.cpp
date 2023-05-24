

#include "DietControllerShowDiets.h"
#include "ViewEngine.h"

namespace diet {
    void DietControllerShowDiets::invoke(const std::wstring &params) const {
        diet::ViewEngine::render("chooseDiet", {});
    }
} // diet