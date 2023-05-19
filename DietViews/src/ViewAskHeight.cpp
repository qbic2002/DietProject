//
// Created by golov on 19.05.2023.
//

#include <iostream>
#include "ViewAskHeight.h"

namespace diet {
    void ViewAskHeight::renderModel(const diet::DietModel& model) const {
        std::string templateString = "Please enter your height (in cm):\n";
        std::cout << templateString << std::endl;
    }
} // view