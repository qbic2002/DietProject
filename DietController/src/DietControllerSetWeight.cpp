//
// Created by golov on 20.05.2023.
//

#include "DietControllerSetWeight.h"
#include "DietApp.h"

namespace diet {
    void DietControllerSetWeight::invoke(const std::wstring &params) const {
        diet::DietService* dietService = diet::DietApp::getInstance()->getDietService();
        dietService->setInitialWeight(std::stof(params));
        redirect("idealWeight");
    }
} // diet