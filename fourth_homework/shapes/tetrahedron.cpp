#include "tetrahedron.h"
#include "shape.h"

extern "C" double calculate_surface_area_tetra(double side);

tetrahedron::tetrahedron(int side, double density) : shape(density) {
    this->side = side;
}

double tetrahedron::calculate_surface_area() {
    return calculate_surface_area_tetra(side);
}

void tetrahedron::to_string(FILE *outputFile) {
    fprintf(outputFile, "[TETRAHEDRON] Side = %d Surface Area = %lf Density = %lf\n",
            side, calculate_surface_area(), density);
}

void tetrahedron::to_string() {
    printf("[TETRAHEDRON] Side = %d Surface Area = %lf Density = %lf\n",
           side, calculate_surface_area(), density);
}
