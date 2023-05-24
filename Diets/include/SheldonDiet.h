//
// Created by msi on 24.05.2023.
//

#ifndef DIETPROJECT_SHELDON_H
#define DIETPROJECT_SHELDON_H

#include <string>
#include "Diet.h"

namespace diet {

    class SheldonDiet : public Diet  {
    private:
    public:
        const std::wstring &getDescription() const override;

        const std::wstring &getPlan() const override;

        int getDietMaxPeriod() const override;

        float getLoosePerDay() const override;

    private:
        std::wstring description_ = L"Описание: ограничений нет, главное правильно совместить продукты.";
        std::wstring plan_ = L"План: План: Для расщепления углеводов нужна щелочная среда, белкам же нужна кислая среда. Соответственно, и есть их нужно в разное время! Этот принцип лег в основу самой легкой диеты для ленивых, которую особенно ценят любители поесть часто и обильно.\n"
                            "Единственное, от чего Шелтон предлагает отказаться — молоко.\n";

        std::wstring name_ = L"Раздельное питание по Шелтону";
    public:
        const std::wstring &getName() const override;

        int dietMaxPeriod_ = 100;
        float loosePerDay_ = 0.03;
    };
}

#endif //DIETPROJECT_SHELDON_H
