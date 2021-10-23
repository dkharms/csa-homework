#ifndef HOMEWORK__SPHERE_H_
#define HOMEWORK__SPHERE_H_

#include "shape.h"

class sphere : public shape {
    int radius;

public:
    sphere(int radius, double density);

    double calculate_surface_area() override;

    void to_string() override;

    void to_string(FILE *outputFile) override;
};

#endif //HOMEWORK__SPHERE_H_
