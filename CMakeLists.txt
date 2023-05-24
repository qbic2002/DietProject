cmake_minimum_required(VERSION 3.25)
project(DietProject)

set(CMAKE_CXX_STANDARD 20)

include(FetchContent)

FetchContent_Declare(json URL https://github.com/nlohmann/json/releases/download/v3.11.2/json.tar.xz)
FetchContent_MakeAvailable(json)


include_directories(include)
include_directories(utils/include)
include_directories(json/include)
include_directories(DietController/include)
include_directories(DietService/include)
include_directories(DietViews/include)
include_directories(DietModels/include)
include_directories(ConsoleInputManager/include)
include_directories(Diets/include)

add_executable(DietProject
        main.cpp
        DietService/src/DietService.cpp
        src/DietApp.cpp
        DietViews/src/ViewEngine.cpp
        DietModels/src/DietModel.cpp
        utils/src/FileUtils.cpp
        ConsoleInputManager/src/ConsoleInputManager.cpp
        DietController/src/DietController.cpp
        DietController/src/DietControllerGreeting.cpp
        DietController/src/DietControllerExit.cpp
        DietController/src/DietControllerInitHeight.cpp
        DietController/src/DietControllerSetHeight.cpp
        DietController/src/DietControllerInitWeight.cpp
        DietController/src/DietControllerSetWeight.cpp
        DietController/src/DietControllerIdealWeight.cpp
        DietViews/src/TemplateToken.cpp
        DietViews/src/TokenContent.cpp
        DietViews/src/TokenIF.cpp
        DietViews/src/TokenElse.cpp
        DietViews/src/TokenCloseIF.cpp
        DietViews/src/TemplateTokenizer.cpp
        DietViews/src/TokenParam.cpp
        DietViews/src/TokenController.cpp
        DietViews/src/TokenContainer.cpp
        DietController/src/DietControllerInitName.cpp
        DietController/src/DietControllerSetName.cpp
        DietController/src/DietControllerShowDiets.cpp
        DietController/src/DietControllerChooseDiet.cpp
        Diets/src/BuckwheatDiet.cpp
        Diets/src/ProteinCarbohydrateDiet.cpp
        Diets/src/ProteinDiet.cpp
        Diets/src/SheldonDiet.cpp
        DietController/src/DietControllerShowDiet.cpp
        DietController/src/DietControllerShowPeriods.cpp
        DietController/src/DietControllerConfirmDiet.cpp DietController/include/DietControllerConfirmDiet.h)

target_link_libraries(DietProject PRIVATE nlohmann_json::nlohmann_json)