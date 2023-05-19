#include <iostream>
#include "json.h"
#include "DietContext.h"

//using json = nlohmann::json;
//using namespace nlohmann::literals;

int main() {
    diet::DietContext::init();
    diet::DietContext::start();
    return 0;
}
