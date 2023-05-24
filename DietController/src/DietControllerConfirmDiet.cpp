//
// Created by msi on 24.05.2023.
//

#include "DietControllerConfirmDiet.h"
#include "Diet.h"
#include "DietService.h"
#include "DietApp.h"

namespace diet {
    void DietControllerConfirmDiet::invoke(const std::wstring &params) const {
        if (params == L"Y") {
            redirect("showPeriods", params);
        } else {
            redirect("showDiets", params);
        }
    }
} // diet