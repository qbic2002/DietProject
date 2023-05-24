

#include "DietControllerSetName.h"
#include "DietService.h"
#include "DietApp.h"

namespace diet {
    void DietControllerSetName::invoke(const std::wstring &params) const {
        diet::DietService* dietService = diet::DietApp::getInstance()->getDietService();
        dietService->setName(params);
        redirect("initHeight");
    }
} // diet