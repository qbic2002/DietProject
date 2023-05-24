//
// Created by msi on 24.05.2023.
//

#ifndef DIETPROJECT_PROTEINCARBOHYDRATEDIET_H
#define DIETPROJECT_PROTEINCARBOHYDRATEDIET_H
#include <string>
#include "Diet.h"

namespace diet {

    class ProteinCarbohydrateDiet : public Diet  {
    private:
    public:
        const std::wstring &getDescription() const override;

        const std::wstring &getPlan() const override;

        const std::wstring &getName() const override;

        int getDietMaxPeriod() const override;

        float getLoosePerDay() const override;

    private:
        std::wstring description_ = L"Если ты не можешь себе представить жизнь без углеводов, обрати внимание на белково-углеводное чередование"
                                   "Это самая легкая диета для похудения в домашних условиях: не надо считать калории, а есть можно все... но не всегда.";
        std::wstring plan_ = L"План: Диета состоит из белковых дней, когда ты резко ограничиваешь углеводы и в умеренных количествах потребляешь жиры, и дней, когда углеводы есть можно (лучше, конечно, сложные), белки допускаются в умеренных количествах, а вот жиры надо ограничить. Описание кажется сложным, но на практике это одна из самых легких диет для эффективного похудения. Просто запомни: если  ты сегодня ешь что-то жирное, то ограничиваешь углеводы и напираешь на белки. А в день, когда ты позволяешь себе углеводы, надо воздержаться от жирного. Все просто!";
        std::wstring name_ = L"Диета белково-углеводного чередования";

        int dietMaxPeriod_ = 100;
        float loosePerDay_ = 0.01;
    };
}
#endif //DIETPROJECT_PROTEINCARBOHYDRATEDIET_H
