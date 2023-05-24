

#ifndef DIETPROJECT_DIETCONTROLLER_H
#define DIETPROJECT_DIETCONTROLLER_H


#include <string>

namespace diet {
    class DietController {
    public:
        virtual void invoke(const std::wstring &params) const = 0; // метод вызова контроллера
        virtual ~DietController() = default;

    protected:
        void redirect(const std::string& controllerName, const std::wstring &params = L"") const; // метод перенаправления запроса на другой контроллер
    };
}


#endif //DIETPROJECT_DIETCONTROLLER_H
