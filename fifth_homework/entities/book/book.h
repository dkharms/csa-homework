#ifndef FIFTH_HOMEWORK_BOOK_H
#define FIFTH_HOMEWORK_BOOK_H

#include <string>
#include "../record/record.h"

class book {
    std::string name_;
    std::string author_;

public:
    book() = default;

    book(std::string name, std::string author);

    std::string name();

    std::string author();
};


#endif //FIFTH_HOMEWORK_BOOK_H
