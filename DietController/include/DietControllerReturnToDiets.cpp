

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