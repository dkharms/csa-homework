#include "row.h"

row::row(int closets_amount, int books_amount) {
    this->closets_amount_ = closets_amount;
    this->books_amount_ = books_amount;
    init();
}

void row::init() {
    for (int i = 0; i < closets_amount_; ++i) {
        closets.push_back(new closet(books_amount_));
    }
}
