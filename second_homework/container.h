#ifndef HOMEWORK__CONTAINER_H_
#define HOMEWORK__CONTAINER_H_

#include "shapes/shape.h"

class container {
    int containerSize;
public:
    shape **shapes;

    container(int size);

    ~container();

    int size();

};

void sort(container *arr, int low, int high);

void fill_container(container *shapeContainer, FILE *inputFile);

void fill_container_random(container *shapeContainer);

#endif //HOMEWORK__CONTAINER_H_
