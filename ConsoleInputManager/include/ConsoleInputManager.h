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



        void setAnyKey(bool anyKey);
        void setControllerName(const std::string& controllerName);
        void setLastViewName(const std::string& lastViewName);
        void setLastModel(const DietModel& lastModel);

        bool isAnyKey() const;
        const std::string& getControllerName() const;
        const std::string& getLastViewName() const;
        const DietModel& getLastModel() const;


    private:
        void callController(const std::wstring &params = L"") const;
        void waitInput();

        void clearConsole() const;
        void pauseConsole() const;

        bool anyKey_;
        std::string controllerName_ = "greeting";

        std::string lastViewName_;
        diet::DietModel lastModel_;
    };
}


#endif //DIETPROJECT_CONSOLEINPUTMANAGER_H
