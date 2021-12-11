#ifndef FIFTH_HOMEWORK_LIBRARY_H
#define FIFTH_HOMEWORK_LIBRARY_H

#include <vector>
#include "../row/row.h"

class library {
    int rows_amount_, closets_amount_, books_amount_;

    void init();

public:
    library(int rows_amount, int closets_amount, int books_amount);

    std::vector<row *> rows;

};


#endif //FIFTH_HOMEWORK_LIBRARY_H
