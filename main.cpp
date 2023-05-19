#include <iostream>
#include "json.h"
#include "DietApp.h"
#include "FileUtils.h"
#include "ViewEngine.h"
#include "DietControllerGreeting.h"
#include "DietControllerExit.h"

//using json = nlohmann::json;
//using namespace nlohmann::literals;

int main() {

    diet::DietApp::getInstance()->init();
    diet::DietApp::getInstance()->setViewDir(R"(D:\CPP\DietProject\views)");

    diet::DietApp::getInstance()->registerController("greeting", new diet::DietControllerGreeting());
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
