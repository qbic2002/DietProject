//
// Created by msi on 24.05.2023.
//

#include "DietControllerConfirmDiet.h"
#include "Diet.h"
#include "DietService.h"
#include "DietApp.h"

namespace diet {
    void DietControllerConfirmDiet::invoke(const std::wstring &params) const {
        DietService* dietService = diet::DietApp::getInstance()->getDietService();
        bool equalOrLess = dietService->getInitialWeight() <= dietService->getIdealWeight();

        if (equalOrLess) {
            redirect("alreadyIdeal", params);
            return;
        }

        if (params == L"Y") {
            redirect("showPeriods", params);
            return;
        } else {
            redirect("showDiets", params);
            return;
        }
    }
} // diet