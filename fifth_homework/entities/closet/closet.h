//
// Created by dkharms on 13.12.2021.
//

#ifndef FIFTH_HOMEWORK_ENTITIES_CLOSET_CLOSET_H_
#define FIFTH_HOMEWORK_ENTITIES_CLOSET_CLOSET_H_

#include <vector>
#include <mutex>
#include <fstream>
#include "../book/book.h"

class closet {
private:
    int books_amount, current_index;
    book **books;
    std::mutex is_adding, is_full;
public:

    closet(int books_amount);

    bool add_book(book *b);

    book *get_book(int index);

    bool full();

    void output(std::fstream &output_stream);

    ~closet();
};

#endif //FIFTH_HOMEWORK_ENTITIES_CLOSET_CLOSET_H_
