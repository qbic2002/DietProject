

#include "DietControllerShowPeriods.h"
#include "ViewEngine.h"
#include "DietService.h"
#include "DietApp.h"
#include "Diet.h"

namespace diet {
    void DietControllerShowPeriods::invoke(const std::wstring &params) const {
        DietService* dietService = diet::DietApp::getInstance()->getDietService();

        Diet* chosenDiet = dietService->chooseDiet(dietService->getDiet());

        DietModel model;
        model.setField(L"maxPeriod", chosenDiet->getDietMaxPeriod());
        diet::ViewEngine::render("choosePeriod", model);
    }
} // diet