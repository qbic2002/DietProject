//
// Created by golov on 19.05.2023.
//

#ifndef DIETPROJECT_DIETCONTEXT_H
#define DIETPROJECT_DIETCONTEXT_H

#include "DietController.h"
#include "DietService.h"

namespace diet {

    class DietContext {
    public:
        DietContext() = delete;

        static void init(); //initialize Services and Controllers
        static void start();

        //getters
        static DietController* getDietController() ;
        static DietService* getDietService() ;

        ~DietContext();

    private:
        static diet::DietController* dietController_;
        static diet::DietService* dietService_;
    };

} // diet

#endif //DIETPROJECT_DIETCONTEXT_H
