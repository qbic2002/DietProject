//
// Created by msi on 24.05.2023.
//

#ifndef DIETPROJECT_DIET_H
#define DIETPROJECT_DIET_H

#include <string>

namespace diet {
    struct Diet {
        virtual const std::wstring& getDescription() const = 0;
        virtual const std::wstring& getPlan() const = 0;
        virtual const std::wstring& getName() const = 0;
        virtual int getDietMaxPeriod() const = 0;
        virtual float getLoosePerDay() const = 0;

        virtual ~Diet() = default;
    };
}

#endif //DIETPROJECT_DIET_H
