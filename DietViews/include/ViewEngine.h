//
// Created by golov on 19.05.2023.
//

#ifndef DIETPROJECT_VIEWENGINE_H
#define DIETPROJECT_VIEWENGINE_H

#include "DietModel.h"

namespace diet {

    class ViewEngine {
    public:
        static void render(const std::string& viewName, const diet::DietModel& model);
    private:
        static std::string parseTemplate(const std::string& templateString, const DietModel& model);
        static void setNextController(const std::string& templateString);
    };

} // diet

#endif //DIETPROJECT_VIEWENGINE_H
