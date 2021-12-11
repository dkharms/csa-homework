#ifndef FIFTH_HOMEWORK_ROW_H
#define FIFTH_HOMEWORK_ROW_H

#include <vector>
#include "../closet/closet.h"

class row {
    int closets_amount_, books_amount_;

    void init();

public:
    explicit row(int closets_amount, int books_amount);

    std::vector<closet *> closets;
};

#endif //FIFTH_HOMEWORK_ROW_H
