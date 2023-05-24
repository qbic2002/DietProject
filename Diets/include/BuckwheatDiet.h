

#ifndef DIETPROJECT_BUCKWHEATDIET_H
#define DIETPROJECT_BUCKWHEATDIET_H

#include <string>
#include "Diet.h"

namespace diet {


    class BuckwheatDiet : public Diet {
    private:
    public:
        const std::wstring &getDescription() const override;

        const std::wstring &getPlan() const override;

        const std::wstring &getName() const override;

        int getDietMaxPeriod() const override;

        float getLoosePerDay() const override;

    private:
        std::wstring description_ = L"Относится к разряду жестких монодиет, предназначена для быстрого похудения."
                                   " Главный ингредиент методики – гречка, которую нужно готовить по специальной технологии.";
        std::wstring plan_ = L"Крупу запрещается варить, она заливается кипятком и настаивается восемь часов. При этом, в нее нельзя добавлять приправы и соль. По истечению данного времени гречневую кашу можно есть в неограниченном количестве.В классической версии диета рассчитана на неделю (за данный период потеря веса составляет 4 – 5 килограмм), при необходимости срок ее соблюдения можно увеличить до 14 дней (минус 6 – 10 килограмм). При похудении, помимо гречки, разрешается пить полтора литра щелочной минеральной воды, зеленый чай и литр кефира с жирностью 1 %."
                            "Если при соблюдении методики чувствуется ухудшение самочувствия, рекомендуется ввести в ежедневный рацион низкокалорийные фрукты (яблоки, апельсины, грейпфрут).";
        std::wstring name_ = L"Гречневая диета";

        int dietMaxPeriod_ = 14;
        float loosePerDay_ = 0.7;
    };
}
#endif //DIETPROJECT_BUCKWHEATDIET_H
