//
// Created by msi on 24.05.2023.
//

#include "ProteinDiet.h"

const std::wstring &diet::ProteinDiet::getDescription() const {
    return description_;
}

const std::wstring &diet::ProteinDiet::getPlan() const {
    return plan_;
}

const std::wstring &diet::ProteinDiet::getName() const {
    return name_;
}

int diet::ProteinDiet::getDietMaxPeriod() const {
    return dietMaxPeriod_;
}

float diet::ProteinDiet::getLoosePerDay() const {
    return loosePerDay_;
}
