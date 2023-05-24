

#ifndef DIETPROJECT_DIETAPP_H
#define DIETPROJECT_DIETAPP_H

#include <filesystem>
#include "DietController.h"
#include "DietService.h"
#include "ConsoleInputManager.h"

namespace diet {

    class DietApp {
    public:
        void init(); // initialize Services and Controllers
        void start(); // start app

        // getters
        DietService* getDietService() const;
        ConsoleInputManager* getConsoleInputManager() const;

        void registerController(const std::string& name, DietController* controller); // регистрация контроллера
        diet::DietController* findController(const std::string& name); // поиск контроллера по имени

        void setViewDir(const std::string& viewsDir); // задание значения папки с щаблонами
        std::filesystem::path findView(const std::string& viewName); // поиск шаблона

        static DietApp* getInstance(); // получение экземпляра класса DietApp (синглтон)
        void freeMemory(); // очистка памяти

        ~DietApp();

    private:
        DietApp() = default;

        diet::DietService* dietService_ = nullptr; // сервис
        diet::ConsoleInputManager* consoleInputManager_ = nullptr; // менеджер ввода с консоли

        std::filesystem::path viewsDir_; // путь до шаблона

        std::unordered_map<std::string, diet::DietController*> controllers_; // хэш таблица с контроллерами и их именами

        static DietApp* instance_; // экземпляр класса DietApp
    };

} // diet

#endif //DIETPROJECT_DIETAPP_H
