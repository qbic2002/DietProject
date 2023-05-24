//
// Created by msi on 24.05.2023.
//

#include "SheldonDiet.h"

const std::wstring &diet::SheldonDiet::getDescription() const {
    return description_;
}

const std::wstring &diet::SheldonDiet::getPlan() const {
    return plan_;
}

const std::wstring &diet::SheldonDiet::getName() const {
    return name_;
}

int diet::SheldonDiet::getDietMaxPeriod() const {
    return dietMaxPeriod_;
}

float diet::SheldonDiet::getLoosePerDay() const {
    return loosePerDay_;
}
