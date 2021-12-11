#include <iostream>
#include "closet.h"


closet::closet(int books_amount) {
    this->books_amount_ = books_amount;
}

void closet::add_book(book *new_book) {
    books_.push_back(new_book);
}

book *closet::get_book(int index) {
    return books_[index];
}

bool closet::full() {
    return books_.size() == books_amount_;
}



