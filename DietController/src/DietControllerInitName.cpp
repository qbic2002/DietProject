

#include "DietControllerInitName.h"
#include "ViewEngine.h"

namespace diet {
    void DietControllerInitName::invoke(const std::wstring &params) const {
        diet::ViewEngine::render("initName", {});
    }
} // diet