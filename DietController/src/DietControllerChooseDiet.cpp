

#include "DietControllerChooseDiet.h"
#include "DietService.h"
#include "DietApp.h"

namespace diet {
    void DietControllerChooseDiet::invoke(const std::wstring &params) const {
        DietService* dietService = diet::DietApp::getInstance()->getDietService();

        int diet = std::stoi(params);
        dietService->setDiet(diet);

        redirect("showDiet", params);
    }
} // diet