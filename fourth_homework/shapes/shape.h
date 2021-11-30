#ifndef HOMEWORK__SHAPE_H_
#define HOMEWORK__SHAPE_H_

#include "cstdio"

class shape {

public:
    double density;

    shape();

    shape(double density);

    ~shape();

    virtual double calculate_surface_area();

    virtual void to_string();

    virtual void to_string(FILE *outputFile);
};

shape *create_shape(char *shapeType, FILE *inputFile);

#endif //HOMEWORK__SHAPE_H_
