#include <Windows.h>
#include "DietApp.h"
#include "FileUtils.h"
#include "DietControllerGreeting.h"
#include "DietControllerExit.h"
#include "DietControllerInitHeight.h"
#include "DietControllerSetHeight.h"
#include "DietControllerInitWeight.h"
#include "DietControllerSetWeight.h"
#include "DietControllerIdealWeight.h"
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

int main() {

    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);

    diet::DietApp::getInstance()->init();

    diet::DietApp::getInstance()->setViewDir(R"(C:\Users\msi\CLionProjects\DietProject\views)");

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
    return 0;
}
