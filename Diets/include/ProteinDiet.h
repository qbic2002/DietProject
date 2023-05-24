//
// Created by msi on 24.05.2023.
//

#ifndef DIETPROJECT_PROTEINDIET_H
#define DIETPROJECT_PROTEINDIET_H

#include <string>
#include "Diet.h"

namespace diet {
    class ProteinDiet : public Diet  {
    public:
        const std::wstring &getDescription() const override;

        const std::wstring &getPlan() const override;
        const std::wstring &getName() const override;

        int getDietMaxPeriod() const override;

        float getLoosePerDay() const override;

    private:
        std::wstring description_ = L"Описание: Главный плюс — Одним словом, самая простая и легкая диета — особенно для тех, кто предпочитает кусок мяса шоколадке.\n"
                                   "Главный минус — этот легкий способ похудеть «бьет» по почкам, поэтому категорически не подходит всем, у кого они не в идеальном состоянии.";
        std::wstring plan_ = L"Диетологи рекомендуют соблюдать белковую диету не дольше 14 дней.\n"
                            "Пример белковой диеты: чередование белкового и белково-овощного дня\n"
                            "Белковый день:\n"
                            "•На завтрак — белковый омлет с зеленью и лососем.\n"
                            "•На второй завтрак — маложирный йогурт.\n"
                            "•На обед — отварное мясо или курица\n"
                            "•На полдник — вареные креветки\n"
                            "•На ужин — стейк из лосося или баранины\n"
                            "•Перед сном — кефир\n"
                            "Белково-овощной день:\n"
                            "•На завтрак — кабачковые оладьи или омлет с зеленым луком, томатами и болгарским перцем\n"
                            "•На второй завтрак — нежирный творог с зеленью\n"
                            "•На обед: салат из тунца с овощами\n"
                            "•На полдник: овощной салат\n"
                            "•На ужин: мясо на гриле с гарниром из тушеной капусты\n";

        std::wstring name_ = L"Белковая диета";

        int dietMaxPeriod_ = 14;
        float loosePerDay_ = 0.8;
    };
}

#endif //DIETPROJECT_PROTEINDIET_H
