

#ifndef DIETPROJECT_DIET_H
#define DIETPROJECT_DIET_H

#include <string>

namespace diet {
    struct Diet {
        virtual const std::wstring& getDescription() const = 0; // описание диеты
        virtual const std::wstring& getPlan() const = 0; // план диеты
        virtual const std::wstring& getName() const = 0; // название диеты
        virtual int getDietMaxPeriod() const = 0; // максимальная длительность диеты
        virtual float getLoosePerDay() const = 0; // потеря кг в день

        virtual ~Diet() = default;
    };
}

#endif //DIETPROJECT_DIET_H
