

#ifndef DIETPROJECT_CONSOLEINPUTMANAGER_H
#define DIETPROJECT_CONSOLEINPUTMANAGER_H


#include <string>
#include "DietModel.h"

namespace diet {

    class ConsoleInputManager {
    public:
        ConsoleInputManager() = default;

        void start();
        void idle(); // ожидание ввода


        // сеттеры
        void setAnyKey(bool anyKey);
        void setControllerName(const std::string& controllerName);
        void setLastViewName(const std::string& lastViewName);
        void setLastModel(const DietModel& lastModel);

        // геттеры
        bool isAnyKey() const;
        const std::string& getControllerName() const;
        const std::string& getLastViewName() const;
        const DietModel& getLastModel() const;


    private:
        void callController(const std::wstring &params = L"") const; // вызов контроллера
        void waitInput(); // ожидание ввода

        void clearConsole() const; // очистка консоли
        void pauseConsole() const; // по сути вызов system("pause")

        bool anyKey_;
        std::string controllerName_ = "greeting";

        std::string lastViewName_;
        diet::DietModel lastModel_;
    };
}


#endif //DIETPROJECT_CONSOLEINPUTMANAGER_H
