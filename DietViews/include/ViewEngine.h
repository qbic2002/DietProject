//
// Created by golov on 19.05.2023.
//

#ifndef DIETPROJECT_VIEWENGINE_H
#define DIETPROJECT_VIEWENGINE_H

#include "DietModel.h"
#include "TemplateToken.h"
#include "TokenContainer.h"

namespace diet {

    class ViewEngine {
    public:
        static void render(const std::string& viewName, const DietModel& model);
        static void clearConsole();
    private:
        static std::wstring parseTemplate(diet::TokenContainer& tokens, const DietModel& model);
        static void parseParamTokens(diet::TokenContainer& tokens, const DietModel& model);
        static void parseIf(diet::TokenContainer& tokens, const DietModel& model);
    };

} // diet

#endif //DIETPROJECT_VIEWENGINE_H
