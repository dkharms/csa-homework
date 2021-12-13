#ifndef FIFTH_HOMEWORK_ENTITIES_RUCKSACK_RUCKSACK_H_
#define FIFTH_HOMEWORK_ENTITIES_RUCKSACK_RUCKSACK_H_

#include <queue>
#include <mutex>
#include "../book/book.h"

class rucksack {
private:
    int books_amount;
    std::queue<book *> books;
    std::mutex is_adding, is_getting, is_empty;

public:
    rucksack(int books_amount);

    void add_book(book *new_book);

    book *get_book();

    int amount();

    bool empty();
};

#endif //FIFTH_HOMEWORK_ENTITIES_RUCKSACK_RUCKSACK_H_
