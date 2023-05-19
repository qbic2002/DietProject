//
// Created by golov on 19.05.2023.
//

#ifndef DIETPROJECT_DIETSERVICE_H
#define DIETPROJECT_DIETSERVICE_H

namespace diet {

    class DietService {
    public:
        DietService() = default;

        float calculateIdealWeight();

        // getters
        unsigned int getHeight() const;
        float getInitialWeight() const;
        float getIdealWeight() const;

        //setters
        void setHeight(unsigned int height);
        void setInitialWeight(float initialWeight);
    private:

        unsigned int height_; //height of the person in cm
        float initialWeight_; //weight of the person in kg

        float idealWeight_;
    };

} // diet

#endif //DIETPROJECT_DIETSERVICE_H
