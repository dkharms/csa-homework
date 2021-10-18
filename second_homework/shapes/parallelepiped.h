#ifndef HOMEWORK__PARALLELEPIPED_H_
#define HOMEWORK__PARALLELEPIPED_H_

#include "shape.h"

class parallelepiped : public shape {
    int width, length, height;

public:
    parallelepiped(int width, int length, int height, double density);

    double calculate_surface_area() override;

    void to_string(FILE *outputFile) override;
};

#endif //HOMEWORK__PARALLELEPIPED_H_
