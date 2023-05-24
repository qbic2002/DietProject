

#include "DietControllerChoosePeriod.h"
#include "DietService.h"
#include "DietApp.h"
#include "ViewEngine.h"

namespace diet {
    void DietControllerChoosePeriod::invoke(const std::wstring& params) const {
        DietService* dietService = diet::DietApp::getInstance()->getDietService();

        Diet* chosenDiet = dietService->chooseDiet(dietService->getDiet());
        int period = std::stoi(params);

        int maxPeriod = chosenDiet->getDietMaxPeriod();

        if (period > maxPeriod) {
            throw std::runtime_error("period is greater than max period");
        }

        float newWeight = dietService->getInitialWeight() - ((float)period * chosenDiet->getLoosePerDay());
        float lostWeight = (float)period * chosenDiet->getLoosePerDay();
        bool isIdeal = std::abs(newWeight - dietService->getIdealWeight()) < 1.5f;
        bool moreThanIdeal = newWeight - dietService->getIdealWeight() >= 1.5f;
        bool lessThanIdeal = dietService->getIdealWeight() - newWeight >= 1.5f;

        DietModel model;
        model.setField(L"newWeight", newWeight);
        model.setField(L"lostWeight", lostWeight);
        model.setField(L"isIdeal", isIdeal);
        model.setField(L"moreThanIdeal", moreThanIdeal);
        model.setField(L"lessThanIdeal", lessThanIdeal);

        diet::ViewEngine::render("result", model);
    }
} // diet