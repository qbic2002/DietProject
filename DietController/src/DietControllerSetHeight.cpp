//
// Created by golov on 20.05.2023.
//

#include "DietControllerSetHeight.h"
#include "DietApp.h"

namespace diet {
    void DietControllerSetHeight::invoke(const std::string& params) const {
        diet::DietService* dietService = diet::DietApp::getInstance()->getDietService();
        dietService->setHeight(std::stoi(params));
        redirect("initWeight");
    }
} // diet