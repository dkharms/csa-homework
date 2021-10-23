#include "cstdlib"
#include "shape.h"
#include "sphere.h"
#include "parallelepiped.h"
#include "tetrahedron.h"
#include "cstring"

shape::shape() {
}

shape::shape(double density) {
    this->density = density;
}

double shape::calculate_surface_area() {
}

shape *create_shape(char *shapeType, FILE *inputFile) {
    double density = rand() % 1000;
    if (!strcmp(shapeType, "sphere")) {
        int radius;
        if (inputFile == nullptr) {
            radius = rand() % 1000;
        } else {
            fscanf(inputFile, "%d %lf\n", &radius, &density);
        }

        return new sphere(radius, density);
    }
    if (!strcmp(shapeType, "parallelepiped")) {
        int width, length, height;
        if (inputFile == nullptr) {
            width = rand() % 1000;
            length = rand() % 1000;
            height = rand() % 1000;
        } else {
            fscanf(inputFile, "%d %d %d %lf\n", &width, &length, &height, &density);
        }

        return new parallelepiped(width, length, height, density);
    }
    if (!strcmp(shapeType, "tetrahedron")) {
        int size;
        if (inputFile == nullptr) {
            size = rand() % 1000;
        } else {
            fscanf(inputFile, "%d %lf\n", &size, &density);
        }

        return new tetrahedron(size, density);
    }
}

void shape::to_string(FILE *outputFile) {
}

void shape::to_string() {
}

shape::~shape() {
}


