//
// Created by dkharms on 11.12.2021.
//

#ifndef FIFTH_HOMEWORK_CLOSET_H
#define FIFTH_HOMEWORK_CLOSET_H

#include <vector>
#include "../book/book.h"

class closet {
    std::vector<book *> books_;
public:

    void set_book(int index, book *new_book) {
        books_[index] = new_book;
    }


};


#endif //FIFTH_HOMEWORK_CLOSET_H
