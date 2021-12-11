#ifndef FIFTH_HOMEWORK_CLOSET_H
#define FIFTH_HOMEWORK_CLOSET_H

#include <vector>
#include "../book/book.h"

class closet {
    int books_amount_;
    std::vector<book *> books_;

public:
    closet() = default;

    closet(int books_amount);

    book *get_book(int index);

    void add_book(book *new_book);

    bool full();
};


#endif //FIFTH_HOMEWORK_CLOSET_H
