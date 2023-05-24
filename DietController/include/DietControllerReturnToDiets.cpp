//
// Created by golov on 24.05.2023.
//

#include "DietControllerReturnToDiets.h"

namespace diet {
    void DietControllerReturnToDiets::invoke(const std::wstring& params) const {
        if (params == L"Y") {
            redirect("showDiets");
            return;
        } else {
            redirect("exit");
        }
    }
} // diet