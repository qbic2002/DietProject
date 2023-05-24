

#include "DietControllerSetWeight.h"
#include "DietApp.h"

namespace diet {
    void DietControllerSetWeight::invoke(const std::wstring &params) const {
        diet::DietService* dietService = diet::DietApp::getInstance()->getDietService();
        dietService->setInitialWeight(std::stof(params));
        redirect("idealWeight");
    }
} // diet