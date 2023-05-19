//
// Created by golov on 19.05.2023.
//

#include <cstdlib>
#include <iostream>
#include "ConsoleInputManager.h"
#include "DietApp.h"
#include "ViewEngine.h"

void diet::ConsoleInputManager::start() {
    callController();
    idle();
}


void diet::ConsoleInputManager::idle() {
    while (true) {
        if (anyKey) {
            pauseConsole();
            clearConsole();
            callController();
        } else {
            waitInput();
        }
    }
}

void diet::ConsoleInputManager::callController(const std::string& params) const {
    DietController* controller = diet::DietApp::getInstance()->findController(controllerName);
    controller->invoke(params);
}

void diet::ConsoleInputManager::waitInput() {
    while (true) {
        try {
            std::string params;
            std::cin >> params;
            callController(params);
        } catch (...) {
            clearConsole();
            diet::ViewEngine::render(lastViewName, lastModel);
            continue;
        }
        break;
    }
}

void diet::ConsoleInputManager::clearConsole() const {
    system("cls");
}

void diet::ConsoleInputManager::pauseConsole() const {
    system("pause");
}
