#include "rucksack.h"

void rucksack::add_book(book *new_record) {
    adding_book_mutex.lock();
    books.push(new_record);
    adding_book_mutex.unlock();
}

book *rucksack::get_book() {
    getting_book_mutex.lock();
    book *next_book = books.front();
    books.pop();
    getting_book_mutex.unlock();

    return next_book;
}

bool rucksack::empty() {
    return books.empty();
}
