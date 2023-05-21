//
// Created by golov on 20.05.2023.
//

#ifndef DIETPROJECT_TEMPLATETOKEN_H
#define DIETPROJECT_TEMPLATETOKEN_H

#include <string>

namespace diet {

    class TemplateToken {
    public:
        enum TokenType {
            CONTENT,
            IF,
            ELSE,
            CLOSE_IF,
            PARAM,
            CONTROLLER
        };


        explicit TemplateToken(const std::string& string);

        virtual TokenType getType() const = 0;
        const std::string& getString() const;
        virtual ~TemplateToken() = default;

        size_t getStartPos() const;
        void setStartPos(size_t startPos);
        size_t getEndPos() const;
        void setEndPos(size_t endPos);


    protected:
        std::string string_;

        std::size_t startPos_;
        std::size_t endPos_;
    };

}


#endif //DIETPROJECT_TEMPLATETOKEN_H
