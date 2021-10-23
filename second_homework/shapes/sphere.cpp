#include "iostream"

#include "cmath"
#include "sphere.h"

sphere::sphere(int radius, double density) : shape(density) {
    this->radius = radius;
}

double sphere::calculate_surface_area() {
    return 4.0 * M_PI * this->radius * this->radius;
}

void sphere::to_string(FILE *outputFile) {
    fprintf(outputFile, "[SPHERE] Radius = %d Surface Area = %lf Density = %lf\n",
            radius, calculate_surface_area(), density);
}

void sphere::to_string() {
    printf("[SPHERE] Radius = %d Surface Area = %lf Density = %lf\n",
           radius, calculate_surface_area(), density);
}


