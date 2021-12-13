//
// Created by dkharms on 13.12.2021.
//

#include "library.h"

library::library(int rows_amount, int closets_amount, int books_amount) {
    this->rows_amount = rows_amount;
    this->closets_amount = closets_amount;
    this->books_amount = books_amount;
    rows = new row *[rows_amount];
    init();
}

void library::init() {
    for (int i = 0; i < amount(); ++i) {
        rows[i] = new row(closets_amount, books_amount);
    }
}

row *library::get_row(int index) {
    return rows[index];
}

int library::amount() {
    return rows_amount;
}
library::~library() {
    for (int i = 0; i < amount(); ++i) {
        delete rows[i];
    }

    delete[] rows;
}


