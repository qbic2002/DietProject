//
// Created by golov on 19.05.2023.
//

#ifndef DIETPROJECT_DIETCONTROLLER_H
#define DIETPROJECT_DIETCONTROLLER_H


namespace diet {
    class DietController {
    public:
        DietController() = default;
        void start();
    private:
        void printGreet() const;
        void askForInitHeight() const;
    };
}


#endif //DIETPROJECT_DIETCONTROLLER_H
