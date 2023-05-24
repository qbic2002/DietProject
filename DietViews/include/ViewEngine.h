

#ifndef DIETPROJECT_VIEWENGINE_H
#define DIETPROJECT_VIEWENGINE_H

#include "DietModel.h"
#include "TemplateToken.h"
#include "TokenContainer.h"

namespace diet {

    class ViewEngine {
    public:
        static void render(const std::string& viewName, const DietModel& model); // рендеринг на консоль
        static void clearConsole(); // очистка консоли
    private:
        static std::wstring parseTemplate(diet::TokenContainer& tokens, const DietModel& model); // парсинг шаблона
        static void parseParamTokens(diet::TokenContainer& tokens, const DietModel& model); // парсинг параметров
        static void parseIf(diet::TokenContainer& tokens, const DietModel& model); // парсинг ifов
    };

} // diet

#endif //DIETPROJECT_VIEWENGINE_H
