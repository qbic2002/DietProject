#include <iostream>
#include <Windows.h>
#include "json.h"
#include "DietApp.h"
#include "FileUtils.h"
#include "ViewEngine.h"
#include "DietControllerGreeting.h"
#include "DietControllerExit.h"
#include "DietControllerInitHeight.h"
#include "DietControllerSetHeight.h"
#include "DietControllerInitWeight.h"
#include "DietControllerSetWeight.h"
#include "DietControllerIdealWeight.h"
#include "TemplateTokenizer.h"
#include "DietControllerInitName.h"
#include "DietControllerSetName.h"
#include "DietControllerShowDiets.h"
#include "DietControllerChooseDiet.h"
#include "DietControllerShowDiet.h"
#include "DietControllerShowPeriods.h"
#include "DietControllerConfirmDiet.h"
#include "DietControllerAlreadyIdeal.h"
#include "DietControllerChoosePeriod.h"
#include "DietControllerReturnToDiets.h"

//using json = nlohmann::json;
//using namespace nlohmann::literals;

int main() {

//    std::string input = "Your ideal weight is {{idealWeight}}\n"
//                        "{#equalOrLess#}\n"
//                        "Your current weight {{initWeight}} is less or equal to ideal, but you still can get info about diets_!{!!}sdjfghs{//}\n"
//                        "\n"
//                        "$exit$";
//    diet::TokenContainer tokens;
//    diet::TemplateTokenizer::tokenize(input, tokens);
//    std::cout << "\n";


    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    diet::DietApp::getInstance()->init();
    diet::DietApp::getInstance()->setViewDir(R"(D:\CPP\DietProject\views)");

//    diet::DietApp::getInstance()->registerController("test", new diet::Test());
    diet::DietApp::getInstance()->registerController("greeting", new diet::DietControllerGreeting());
    diet::DietApp::getInstance()->registerController("initName", new diet::DietControllerInitName());
    diet::DietApp::getInstance()->registerController("setName", new diet::DietControllerSetName());
    diet::DietApp::getInstance()->registerController("initHeight", new diet::DietControllerInitHeight());
    diet::DietApp::getInstance()->registerController("setHeight", new diet::DietControllerSetHeight());
    diet::DietApp::getInstance()->registerController("initWeight", new diet::DietControllerInitWeight());
    diet::DietApp::getInstance()->registerController("setWeight", new diet::DietControllerSetWeight());
    diet::DietApp::getInstance()->registerController("idealWeight", new diet::DietControllerIdealWeight());
    diet::DietApp::getInstance()->registerController("showDiets", new diet::DietControllerShowDiets());
    diet::DietApp::getInstance()->registerController("chooseDiet", new diet::DietControllerChooseDiet());
    diet::DietApp::getInstance()->registerController("showDiet", new diet::DietControllerShowDiet());
    diet::DietApp::getInstance()->registerController("confirmDiet", new diet::DietControllerConfirmDiet());
    diet::DietApp::getInstance()->registerController("showPeriods", new diet::DietControllerShowPeriods());
    diet::DietApp::getInstance()->registerController("alreadyIdeal", new diet::DietControllerAlreadyIdeal());
    diet::DietApp::getInstance()->registerController("choosePeriod", new diet::DietControllerChoosePeriod());
    diet::DietApp::getInstance()->registerController("returnToDiets", new diet::DietControllerReturnToDiets());
    diet::DietApp::getInstance()->registerController("exit", new diet::DietControllerExit());

    diet::DietApp::getInstance()->start();

    diet::DietApp::getInstance()->freeMemory();

//    diet::ViewEngine eng;
//    diet::DietModel model;
//    model.setField("myName", "Max");
//    model.setField("last", "Test");
//    eng.render("D:\\CPP\\DietProject\\test.txt", model);
//
//    json j = R"({"mem": 12})"_json;
//    std::cout << to_string(j["mem"]) << std::endl;
    return 0;
}
