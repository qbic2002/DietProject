//
// Created by golov on 19.05.2023.
//

#include <iostream>
#include "DietController.h"
#include "ViewGreeting.h"
#include "ViewAskHeight.h"
#include "DietContext.h"

namespace diet {

    void DietController::start() {
        while (true) {
            printGreet();
            system("pause");
            system("cls");

            askForInitHeight();
        }
    }

    void DietController::printGreet() const {
        diet::ViewGreeting viewGreeting;
        viewGreeting.renderModel({});
    }

    void DietController::askForInitHeight() const {
        while (true) {
            try {
                diet::ViewAskHeight viewAskHeight;
                viewAskHeight.renderModel({});

                unsigned int height;
                std::cin >> height;
                diet::DietContext::getDietService()->setHeight(height);
            } catch (...) {
                system("cls");
//                continue;
            }

            break;
        }
    }
}