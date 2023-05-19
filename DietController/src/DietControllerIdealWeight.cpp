//
// Created by golov on 20.05.2023.
//

#include "DietControllerIdealWeight.h"
#include "ViewEngine.h"
#include "DietService.h"
#include "DietApp.h"

namespace diet {
    void DietControllerIdealWeight::invoke(const std::string& params) const {
        diet::DietService* dietService = diet::DietApp::getInstance()->getDietService();

        dietService->calculateIdealWeight();
        bool equalOrLess = dietService->getInitialWeight() <= dietService->getIdealWeight();

        diet::DietModel model;
        model.setField("equalOrLess", equalOrLess);
        model.setField("initWeight", dietService->getInitialWeight());
        model.setField("idealWeight", dietService->getIdealWeight());

        diet::ViewEngine::render("idealWeight", model);
    }
} // diet