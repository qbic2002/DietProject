//
// Created by golov on 19.05.2023.
//

#ifndef DIETPROJECT_DIETSERVICE_H
#define DIETPROJECT_DIETSERVICE_H

#include <string>

namespace diet {

    class DietService {
    public:
        DietService() = default;

        float calculateIdealWeight();

        // getters
        unsigned int getHeight() const;
        float getInitialWeight() const;
        float getIdealWeight() const;
        const std::string& getName() const;

        //setters
        void setHeight(unsigned int height);
        void setInitialWeight(float initialWeight);
        void setName(const std::string& name);
    private:

        unsigned int height_; //height of the person in cm
        float initialWeight_; //weight of the person in kg

        float idealWeight_;

        std::string name_;
    };

} // diet

#endif //DIETPROJECT_DIETSERVICE_H
