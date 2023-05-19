//
// Created by golov on 19.05.2023.
//

#ifndef DIETPROJECT_VIEW_H
#define DIETPROJECT_VIEW_H

#include "DietModel.h"

namespace diet {

    class View {
    public:
        virtual void renderModel(const diet::DietModel& model) const = 0;
        virtual ~View() = default;
    };

} // diet

#endif //DIETPROJECT_VIEW_H
