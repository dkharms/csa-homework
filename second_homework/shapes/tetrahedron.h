#ifndef HOMEWORK__TETRAHEDRON_H_
#define HOMEWORK__TETRAHEDRON_H_

#include "shape.h"

class tetrahedron : public shape {
    int side;

public:
    tetrahedron(int side, double density);

    double calculate_surface_area() override;

    void to_string() override;

    void to_string(FILE *outputFile) override;
};

#endif //HOMEWORK__TETRAHEDRON_H_
