//
// Created by golov on 19.05.2023.
//

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

        void registerController(const std::string& name, DietController* controller);
        diet::DietController* findController(const std::string& name);

        void setViewDir(const std::string& viewsDir);
        std::filesystem::path findView(const std::string& viewName);

        static DietApp* getInstance();
        void freeMemory();

        ~DietApp();

    private:
        DietApp() = default;

        diet::DietService* dietService_ = nullptr;
        diet::ConsoleInputManager* consoleInputManager_ = nullptr;

        std::filesystem::path viewsDir_;

        std::unordered_map<std::string, diet::DietController*> controllers_;

        static DietApp* instance_;
    };

} // diet

#endif //DIETPROJECT_DIETAPP_H
