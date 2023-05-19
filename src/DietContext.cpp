//
// Created by golov on 19.05.2023.
//

#include "DietContext.h"

namespace diet {
    DietController* DietContext::dietController_ = nullptr;
    DietService* DietContext::dietService_ = nullptr;

    void DietContext::init() {
        dietController_ = new DietController();
        dietService_ = new DietService();
    }
    void DietContext::start() {
        dietController_->start();
    }

    DietController* DietContext::getDietController() {
        return dietController_;
    }
    DietService* DietContext::getDietService() {
        return dietService_;
    }

    DietContext::~DietContext() {
        delete dietService_;
        delete dietController_;
    }
} // diet