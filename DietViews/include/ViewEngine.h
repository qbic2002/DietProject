//
// Created by golov on 19.05.2023.
//

#ifndef DIETPROJECT_VIEWENGINE_H
#define DIETPROJECT_VIEWENGINE_H

#include "DietModel.h"
#include "TemplateToken.h"

namespace diet {

    class ViewEngine {
    public:
        static void render(const std::string& viewName, const diet::DietModel& model);
        static void clearConsole();
    private:
        static std::string parseTemplate(std::vector<diet::TemplateToken*>& tokens, const DietModel& model);
        static void parseParamTokens(std::vector<diet::TemplateToken*>& tokens, const DietModel& model);
        static void parseIf(std::vector<diet::TemplateToken*>& tokens, const DietModel& model);
    };

} // diet

#endif //DIETPROJECT_VIEWENGINE_H
