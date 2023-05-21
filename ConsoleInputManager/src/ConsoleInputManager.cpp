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
        if (anyKey_) {
            pauseConsole();
            clearConsole();
            callController();
        } else {
            waitInput();
        }
    }
}

void diet::ConsoleInputManager::callController(const std::string& params) const {
    DietController* controller = diet::DietApp::getInstance()->findController(controllerName_);
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
            diet::ViewEngine::render(lastViewName_, lastModel_);
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

bool diet::ConsoleInputManager::isAnyKey() const {
    return anyKey_;
}

void diet::ConsoleInputManager::setAnyKey(bool anyKey) {
    anyKey_ = anyKey;
}

const std::string& diet::ConsoleInputManager::getControllerName() const {
    return controllerName_;
}

void diet::ConsoleInputManager::setControllerName(const std::string& controllerName) {
    controllerName_ = controllerName;
}

const std::string& diet::ConsoleInputManager::getLastViewName() const {
    return lastViewName_;
}

void diet::ConsoleInputManager::setLastViewName(const std::string& lastViewName) {
    lastViewName_ = lastViewName;
}

const diet::DietModel& diet::ConsoleInputManager::getLastModel() const {
    return lastModel_;
}

void diet::ConsoleInputManager::setLastModel(const diet::DietModel& lastModel) {
    lastModel_ = lastModel;
}
