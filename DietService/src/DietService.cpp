//
// Created by golov on 19.05.2023.
//

#include <stdexcept>
#include "DietService.h"
#include "ProteinDiet.h"
#include "SheldonDiet.h"
#include "ProteinCarbohydrateDiet.h"
#include "BuckwheatDiet.h"

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

    const std::wstring & DietService::getName() const {
        return name_;
    }
    void DietService::setName(const std::wstring &name) {
        name_ = name;
    }

    int DietService::getDiet() const {
        return diet_;
    }

    void DietService::setDiet(int diet) {
        if (1 <= diet && diet <= 4) {
            diet_ = diet;
        } else {
            throw std::runtime_error("incorrect input");
        }
    }

    Diet * DietService::chooseDiet(int diet) {
        setDiet(diet);

        return diets_[diet - 1];
    }
} // diet