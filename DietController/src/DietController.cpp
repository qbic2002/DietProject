

#include "DietController.h"
#include "DietApp.h"

void diet::DietController::redirect(const std::string& controllerName, const std::wstring &params) const {
    auto controller = diet::DietApp::getInstance()->findController(controllerName);
    controller->invoke(params);
}
