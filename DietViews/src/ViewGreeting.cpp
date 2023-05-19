//
// Created by golov on 19.05.2023.
//

#include <iostream>
#include "ViewGreeting.h"

namespace diet {
    void ViewGreeting::renderModel(const DietModel& model) const {
        std::string templateString = "Hello! This is the Diet App!\nPress any button if you want to continue...";
        std::cout << templateString << std::endl;
    }
} // diet