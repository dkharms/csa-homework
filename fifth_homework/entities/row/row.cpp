//
// Created by dkharms on 13.12.2021.
//

#include "row.h"

row::row(int closets_amount, int books_amount) {
    this->closets_amount = closets_amount;
    this->books_amount = books_amount;
    closets = new closet *[closets_amount];
    init();
}

closet *row::get_closet(int index) {
    return closets[index];
}

void row::init() {
    for (int i = 0; i < amount(); ++i) {
        closets[i] = new closet(books_amount);
    }
}

int row::amount() {
    return closets_amount;
}

row::~row() {
    for (int i = 0; i < amount(); ++i) {
        delete closets[i];
    }

    delete[] closets;
}

void row::output(std::fstream &output_stream) {
    output_stream << "[ROW]" << '\n';
    for (int i = 0; i < closets_amount; ++i) {
        closets[i]->output(output_stream);
    }
}
