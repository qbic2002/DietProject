cmake_minimum_required(VERSION 3.25)
project(DietProject)

set(CMAKE_CXX_STANDARD 20)

include(FetchContent)

FetchContent_Declare(json URL https://github.com/nlohmann/json/releases/download/v3.11.2/json.tar.xz)
FetchContent_MakeAvailable(json)


include_directories(include)
include_directories(json/include)
include_directories(DietController/include)
include_directories(DietService/include)
include_directories(DietViews/include)
include_directories(DietModels/include)

add_executable(DietProject
        main.cpp
        DietService/src/DietService.cpp
        DietController/src/DietController.cpp
        src/DietContext.cpp
        DietViews/src/View.cpp
        DietModels/src/DietModel.cpp
        DietViews/src/ViewGreeting.cpp
        DietViews/src/ViewAskHeight.cpp)

target_link_libraries(DietProject PRIVATE nlohmann_json::nlohmann_json)