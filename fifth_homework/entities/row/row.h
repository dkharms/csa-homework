//
// Created by dkharms on 13.12.2021.
//

#ifndef FIFTH_HOMEWORK_ENTITIES_ROW_ROW_H_
#define FIFTH_HOMEWORK_ENTITIES_ROW_ROW_H_

#include "../closet/closet.h"

class row {
private:
    int books_amount, closets_amount, current_index;
    closet **closets;
    void init();

public:
    row(int closets_amount, int books_amount);

    closet *get_closet(int index);

    int amount();

    void output(std::fstream &output_stream);

    ~row();
};

#endif //FIFTH_HOMEWORK_ENTITIES_ROW_ROW_H_
