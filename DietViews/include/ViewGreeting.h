//
// Created by golov on 19.05.2023.
//

#ifndef DIETPROJECT_VIEWGREETING_H
#define DIETPROJECT_VIEWGREETING_H

#include "View.h"

namespace diet {

    class ViewGreeting : public diet::View {
    public:
        void renderModel(const DietModel& model) const override;
    };

} // diet

#endif //DIETPROJECT_VIEWGREETING_H
