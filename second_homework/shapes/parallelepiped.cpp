#include "iostream"

#include "parallelepiped.h"

parallelepiped::parallelepiped(int width, int length, int height, double density) : shape(density) {
    this->width = width;
    this->length = length;
    this->height = height;
}

double parallelepiped::calculate_surface_area() {
    return 2.0 * (this->height * this->height + this->width * this->length + this->width * this->height);
}

void parallelepiped::to_string(FILE *outputFile) {
    fprintf(outputFile, "[PARALLELEPIPED] Width = %d Length = %d Height = %d Surface Area = %lf Density = %lf\n",
            width, length, height, calculate_surface_area(), density);
}
