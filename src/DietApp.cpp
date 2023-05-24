

#include "DietApp.h"

namespace diet {

    void DietApp::init() {
        dietService_ = new DietService();
        consoleInputManager_ = new ConsoleInputManager();
    }
    void DietApp::start() {
        getConsoleInputManager()->start();
    }


    DietService* DietApp::getDietService() const {
        return dietService_;
    }
    ConsoleInputManager* DietApp::getConsoleInputManager() const {
        return consoleInputManager_;
    }

    void DietApp::registerController(const std::string& name, DietController* controller) {
        controllers_.insert(std::make_pair(name, controller));
    }
    diet::DietController* DietApp::findController(const std::string& name) {
        auto iterator = controllers_.find(name);
        if (iterator == controllers_.end()) {
            throw std::runtime_error("no such a controller");
        }

        return iterator->second;
    }

    void DietApp::setViewDir(const std::string& viewsDir) {
        viewsDir_ = viewsDir;
    }
    std::filesystem::path DietApp::findView(const std::string& viewName) {
        std::filesystem::path viewPath = viewsDir_;
        viewPath.append(viewName).replace_extension("tpl");
        return viewPath;
    }

    DietApp::~DietApp() {
//        freeMemory();
    }

    DietApp* DietApp::getInstance() {
        if (!instance_) {
            instance_ = new DietApp();
        }
        return instance_;
    }

    DietApp* DietApp::instance_ = nullptr;

    void DietApp::freeMemory() {
        delete dietService_;
        dietService_ = nullptr;

        delete consoleInputManager_;
        consoleInputManager_ = nullptr;

        for (auto& node : controllers_) {
            delete node.second;
        }

        controllers_.clear();

        delete instance_;
        instance_ = nullptr;
    }
} // diet