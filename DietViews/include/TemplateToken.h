

#ifndef DIETPROJECT_TEMPLATETOKEN_H
#define DIETPROJECT_TEMPLATETOKEN_H

#include <string>

namespace diet {

    class TemplateToken {
    public:
        enum TokenType { // перечисление типа токена
            CONTENT,
            IF,
            ELSE,
            CLOSE_IF,
            PARAM,
            CONTROLLER
        };


        explicit TemplateToken(const std::wstring& string);

        virtual TokenType getType() const = 0; // тип токена
        const std::wstring& getString() const; // строка токена (геттер)
        virtual ~TemplateToken() = default;

        // геттеры
        size_t getStartPos() const;
        size_t getEndPos() const;

        // сеттеры
        void setStartPos(size_t startPos);
        void setEndPos(size_t endPos);


    protected:
        std::wstring string_; // строка токена

        std::size_t startPos_; // начальная позиция токена в строке
        std::size_t endPos_; // конечная позиция токена в строке
    };

}


#endif //DIETPROJECT_TEMPLATETOKEN_H
