//
// Created by golov on 19.05.2023.
//

#include <iostream>
#include "ViewEngine.h"
#include "FileUtils.h"
#include "DietApp.h"

namespace diet {
    void ViewEngine::render(const std::string& viewName, const DietModel& model) {
        diet::DietApp::getInstance()->getConsoleInputManager()->lastViewName = viewName;
        diet::DietApp::getInstance()->getConsoleInputManager()->lastModel = model;

        std::string templateString = utils::readFile(diet::DietApp::getInstance()->findView(viewName).string()); //TODO findView in App
        std::string renderString = parseTemplate(templateString, model);

        setNextController(templateString);

        std::cout << renderString << std::endl;
    }

    std::string ViewEngine::parseTemplate(const std::string& templateString, const DietModel& model) {
        std::string renderString = templateString;
        std::size_t pos = 0;
        while (true) {
            pos = renderString.find("{{", pos);
            if (pos == std::string::npos) {
                break;
            }
            std::size_t closingPos = renderString.find("}}", pos);
            if (closingPos == std::string::npos) {
                throw std::runtime_error("incorrect template");
            }

            std::string paramName = renderString.substr(pos + 2, closingPos - pos - 2);
            std::string paramValue = model.getField(paramName);

            renderString.replace(pos, closingPos - pos + 2, paramValue);
            pos = closingPos - (paramName.length() + 2 - paramValue.length());
        }

        pos = renderString.find("\n$");
        if (pos == std::string::npos) {
            throw std::runtime_error("incorrect template");
        }
        renderString.erase(renderString.begin() + pos, renderString.end());
        return renderString;
    }

    void ViewEngine::setNextController(const std::string& templateString) {
        std::size_t pos = templateString.find("\n$");
        if (pos == std::string::npos) {
            throw std::runtime_error("incorrect template");
        }

        std::size_t endPos = templateString.find(' ', pos);
        if (endPos == std::string::npos) {
            endPos = templateString.find('$', pos + 2);
            if (endPos == std::string::npos) {
                endPos = templateString.length();
            }
        }

        std::string controllerName = templateString.substr(pos + 2, endPos - (pos + 2));
        diet::DietApp::getInstance()->getConsoleInputManager()->controllerName = controllerName;

        if (templateString.ends_with('$')) {
            diet::DietApp::getInstance()->getConsoleInputManager()->anyKey = true;
        } else {
            diet::DietApp::getInstance()->getConsoleInputManager()->anyKey = false;

        }
    }
} // diet