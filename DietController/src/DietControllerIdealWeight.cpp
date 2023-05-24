

#include "DietControllerIdealWeight.h"
#include "ViewEngine.h"
#include "DietService.h"
#include "DietApp.h"

namespace diet {
    void DietControllerIdealWeight::invoke(const std::wstring &params) const {
        diet::DietService* dietService = diet::DietApp::getInstance()->getDietService();

        dietService->calculateIdealWeight();
        bool equalOrLess = dietService->getInitialWeight() <= dietService->getIdealWeight();

        diet::DietModel model;
        model.setField(L"equalOrLess", equalOrLess);
        model.setField(L"initWeight", dietService->getInitialWeight());
        model.setField(L"idealWeight", dietService->getIdealWeight());

        diet::ViewEngine::render("idealWeight", model);
    }
} // diet