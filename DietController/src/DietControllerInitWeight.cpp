

#include "DietControllerInitWeight.h"
#include "ViewEngine.h"

namespace diet{

    void DietControllerInitWeight::invoke(const std::wstring &params) const {
        diet::ViewEngine::render("initWeight", {});
    }
}