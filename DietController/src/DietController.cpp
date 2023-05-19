//
// Created by golov on 19.05.2023.
//

#include "DietController.h"
#include "DietApp.h"

void diet::DietController::redirect(const std::string& controllerName, const std::string& params) {
    auto controller = diet::DietApp::getInstance()->findController(controllerName);
    controller->invoke(params);
}
