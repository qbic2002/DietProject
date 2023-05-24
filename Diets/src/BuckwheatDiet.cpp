

#include "BuckwheatDiet.h"

const std::wstring &diet::BuckwheatDiet::getDescription() const {
    return description_;
}

const std::wstring &diet::BuckwheatDiet::getPlan() const {
    return plan_;
}

const std::wstring &diet::BuckwheatDiet::getName() const {
    return name_;
}

int diet::BuckwheatDiet::getDietMaxPeriod() const {
    return dietMaxPeriod_;
}

float diet::BuckwheatDiet::getLoosePerDay() const {
    return loosePerDay_;
}
