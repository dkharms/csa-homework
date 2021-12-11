#ifndef FIFTH_HOMEWORK_RUCKSACK_H
#define FIFTH_HOMEWORK_RUCKSACK_H

#include <mutex>
#include <queue>
#include "../book/book.h"

class rucksack {
    std::mutex adding_book_mutex;
    std::mutex getting_book_mutex;
    std::queue<book *> books;

public:
    void add_book(book *new_record);

    book *get_book();

    bool empty();
};

#endif //FIFTH_HOMEWORK_RUCKSACK_H
