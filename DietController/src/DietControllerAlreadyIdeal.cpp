

#include "DietControllerAlreadyIdeal.h"
#include "ViewEngine.h"

namespace diet {
    void DietControllerAlreadyIdeal::invoke(const std::wstring& params) const {
        diet::ViewEngine::render("alreadyIdeal", {});
    }
} // diet