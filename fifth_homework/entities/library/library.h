//
// Created by dkharms on 13.12.2021.
//

#ifndef FIFTH_HOMEWORK_ENTITIES_LIBRARY_LIBRARY_H_
#define FIFTH_HOMEWORK_ENTITIES_LIBRARY_LIBRARY_H_

#include "../row/row.h"

class library {
    int rows_amount, closets_amount, books_amount;
    row **rows;

    void init();
public:

    library(int rows_amount, int closets_amount, int books_amount);

    row *get_row(int index);

    int amount();

    ~library();
};

#endif //FIFTH_HOMEWORK_ENTITIES_LIBRARY_LIBRARY_H_
