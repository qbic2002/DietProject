//
// Created by msi on 24.05.2023.
//

#include "ProteinCarbohydrateDiet.h"

const std::wstring &diet::ProteinCarbohydrateDiet::getDescription() const {
    return description_;
}

const std::wstring &diet::ProteinCarbohydrateDiet::getPlan() const {
    return plan_;
}

const std::wstring &diet::ProteinCarbohydrateDiet::getName() const {
    return name_;
}

int diet::ProteinCarbohydrateDiet::getDietMaxPeriod() const {
    return dietMaxPeriod_;
}

float diet::ProteinCarbohydrateDiet::getLoosePerDay() const {
    return loosePerDay_;
}
