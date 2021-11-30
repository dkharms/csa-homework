#include "parallelepiped.h"

extern "C" double calculate_surface_area_parallelepiped(double width, double length, double height);

parallelepiped::parallelepiped(int width, int length, int height, double density) : shape(density) {
    this->width = width;
    this->length = length;
    this->height = height;
}

double parallelepiped::calculate_surface_area() {
    return calculate_surface_area_parallelepiped(width, length, height);
}

void parallelepiped::to_string(FILE *outputFile) {
    fprintf(outputFile, "[PARALLELEPIPED] Width = %d Length = %d Height = %d Surface Area = %lf Density = %lf\n",
            width, length, height, calculate_surface_area(), density);
}

void parallelepiped::to_string() {
    printf("[PARALLELEPIPED] Width = %d Length = %d Height = %d Surface Area = %lf Density = %lf\n",
           width, length, height, calculate_surface_area(), density);
}
