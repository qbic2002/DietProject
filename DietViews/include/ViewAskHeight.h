//
// Created by golov on 19.05.2023.
//

#ifndef DIETPROJECT_VIEWASKHEIGHT_H
#define DIETPROJECT_VIEWASKHEIGHT_H

#include "View.h"

namespace diet {

    class ViewAskHeight : public diet::View {
    public:
        void renderModel(const diet::DietModel& model) const override;
    };

} // view

#endif //DIETPROJECT_VIEWASKHEIGHT_H
