//
// Created by golov on 19.05.2023.
//

#ifndef DIETPROJECT_CONSOLEINPUTMANAGER_H
#define DIETPROJECT_CONSOLEINPUTMANAGER_H


#include <string>
#include "DietModel.h"

namespace diet {

    class ConsoleInputManager {
    public:
        ConsoleInputManager() = default;

        void start();
        void idle();

        bool anyKey;
        std::string controllerName = "greeting";

        std::string lastViewName;
        diet::DietModel lastModel;
    private:
        void callController(const std::string& params = "") const;
        void waitInput();

        void clearConsole() const;
        void pauseConsole() const;
    };
}


#endif //DIETPROJECT_CONSOLEINPUTMANAGER_H
