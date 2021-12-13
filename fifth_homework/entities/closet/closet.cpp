//
// Created by dkharms on 13.12.2021.
//
#include <iostream>
#include "closet.h"


closet::closet(int books_amount) {
    this->books_amount = books_amount;
    current_index = 0;
    books = new book *[books_amount]();
}

bool closet::add_book(book *b) {
    is_adding.lock();
    bool flag = false;
    if (current_index < books_amount) {
        books[current_index++] = b;
        flag = true;
    }
    is_adding.unlock();

    return flag;
}

bool closet::full() {
    is_full.lock();
    bool b = current_index == books_amount;
    is_full.unlock();

    return b;
}

book *closet::get_book(int index) {
    return books[index];
}

closet::~closet() {
    for (int i = 0; i < books_amount; ++i) {
        if (books[i] != nullptr)
            delete books[i];
    }

    delete[] books;
}

void closet::output(std::fstream &output_stream) {
    output_stream << "  " << "[CLOSET]" << '\n';
    for (int i = 0; i < books_amount; ++i) {
        if (books[i] != nullptr) {
            books[i]->output(output_stream);
        }
    }
}
