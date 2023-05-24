//
// Created by golov on 19.05.2023.
//

#ifndef DIETPROJECT_DIETSERVICE_H
#define DIETPROJECT_DIETSERVICE_H

#include <string>
#include "Diet.h"
#include "ProteinDiet.h"
#include "SheldonDiet.h"
#include "ProteinCarbohydrateDiet.h"
#include "BuckwheatDiet.h"

namespace diet {

    class DietService {
    public:
        DietService() = default;

        float calculateIdealWeight();

        Diet *chooseDiet(int diet);

        // getters
        unsigned int getHeight() const;

        float getInitialWeight() const;

        float getIdealWeight() const;

        const std::wstring &getName() const;

        int getDiet() const;


        //setters
        void setHeight(unsigned int height);

        void setInitialWeight(float initialWeight);

        void setName(const std::wstring &name);

        void setDiet(int diet);

    private:

        unsigned int height_; //height of the person in cm
        float initialWeight_; //weight of the person in kg

        float idealWeight_;

        int diet_;

        std::wstring name_;

        diet::Diet *diets_[4] = {new diet::ProteinDiet(), new diet::SheldonDiet(), new diet::ProteinCarbohydrateDiet(),
                                 new diet::BuckwheatDiet()};
    };

} // diet

#endif //DIETPROJECT_DIETSERVICE_H
