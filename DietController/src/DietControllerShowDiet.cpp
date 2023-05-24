

#include "DietControllerShowDiet.h"
#include "DietApp.h"
#include "ViewEngine.h"

namespace diet {
    void DietControllerShowDiet::invoke(const std::wstring &params) const {
        DietService* dietService = diet::DietApp::getInstance()->getDietService();

        Diet* chosenDiet = dietService->chooseDiet(dietService->getDiet());

        DietModel model;
        model.setField(L"dietName", chosenDiet->getName());
        model.setField(L"description", chosenDiet->getDescription());
        model.setField(L"plan", chosenDiet->getPlan());
        diet::ViewEngine::render("showDiet", model);
    }
} // diet