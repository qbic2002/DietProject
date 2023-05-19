//
// Created by golov on 19.05.2023.
//

#include "DietService.h"

namespace diet {
    float DietService::calculateIdealWeight() {
        idealWeight_ = ((float)height_ - 110) * 1.15F;
        return idealWeight_;
    }

    unsigned int DietService::getHeight() const {
        return height_;
    }
    float DietService::getInitialWeight() const {
        return initialWeight_;
    }
    float DietService::getIdealWeight() const {
        return idealWeight_;
    }

    void DietService::setHeight(unsigned int height) {
        height_ = height;
    }
    void DietService::setInitialWeight(float initialWeight) {
        initialWeight_ = initialWeight;
    }
} // diet