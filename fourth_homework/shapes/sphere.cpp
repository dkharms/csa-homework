#include "sphere.h"

extern "C" double calculate_surface_area_sphere(double radius);

sphere::sphere(int radius, double density) : shape(density) {
    this->radius = radius;
}

double sphere::calculate_surface_area() {
    return calculate_surface_area_sphere(radius);
}

void sphere::to_string(FILE *outputFile) {
    fprintf(outputFile, "[SPHERE] Radius = %d Surface Area = %lf Density = %lf\n",
            radius, calculate_surface_area(), density);
}

void sphere::to_string() {
    printf("[SPHERE] Radius = %d Surface Area = %lf Density = %lf\n",
           radius, calculate_surface_area(), density);
}


