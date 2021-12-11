#include "library.h"


library::library(int rows_amount, int closets_amount, int books_amount) {
    this->rows_amount_ = rows_amount;
    this->closets_amount_ = closets_amount;
    this->books_amount_ = books_amount;
    init();
}

void library::init() {
    for (int i = 0; i < rows_amount_; ++i) {
        rows.push_back(new row(closets_amount_, books_amount_));
    }
}
