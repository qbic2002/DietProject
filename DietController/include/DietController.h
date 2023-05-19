//
// Created by golov on 19.05.2023.
//

#ifndef DIETPROJECT_DIETCONTROLLER_H
#define DIETPROJECT_DIETCONTROLLER_H


#include <string>

namespace diet {
    class DietController {
    public:
        virtual void invoke(const std::string& params) const = 0;
        virtual ~DietController() = default;

    protected:
        void redirect(const std::string& controllerName, const std::string& params = "") const;
    };
}


#endif //DIETPROJECT_DIETCONTROLLER_H
