

#include "DietControllerInitHeight.h"
#include "ViewEngine.h"
#include "DietApp.h"
#include "DietService.h"

namespace diet {
    void DietControllerInitHeight::invoke(const std::wstring &params) const {
        diet::DietService* dietService = diet::DietApp::getInstance()->getDietService();


        diet::DietModel model;
        model.setField(L"name", dietService->getName());
        diet::ViewEngine::render("initHeight", model);
    }
} // diet