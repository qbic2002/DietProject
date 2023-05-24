

#include "DietControllerSetHeight.h"
#include "DietApp.h"

namespace diet {
    void DietControllerSetHeight::invoke(const std::wstring &params) const {
        diet::DietService* dietService = diet::DietApp::getInstance()->getDietService();
        dietService->setHeight(std::stoi(params));
        redirect("initWeight");
    }
} // diet