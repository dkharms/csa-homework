//
// Created by dkharms on 13.12.2021.
//

#include <iostream>
#include "rucksack.h"

rucksack::rucksack(int books_amount) {
    this->books_amount = books_amount;
}

void rucksack::add_book(book *new_book) {
    is_adding.lock();
    books.push(new_book);
    is_adding.unlock();
}

book *rucksack::get_book() {
    is_getting.lock();
    book *current_book = nullptr;
    if (!books.empty()) {
        current_book = books.front();
        books.pop();
    }
    is_getting.unlock();

    return current_book;
}

bool rucksack::empty() {
    is_empty.lock();
    bool emp = books.empty();
    is_empty.unlock();

    return emp;
}

int rucksack::amount() {
    return books_amount;
}
