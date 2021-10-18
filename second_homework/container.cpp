#include "shapes/shape.h"
#include "container.h"
#include "cstdlib"
#include "cstdio"
#include "shapes/sphere.h"
#include "shapes/tetrahedron.h"
#include "shapes/parallelepiped.h"

container::container(int containerSize) {
    this->containerSize = containerSize;
    this->shapes = new shape *[containerSize];
}

int container::size() {
    return this->containerSize;
}

void fill_container(container *shapeContainer, FILE *inputFile) {
    for (int i = 0; i < shapeContainer->size(); ++i) {
        char shapeType;
        fscanf(inputFile, "%c", &shapeType);
        if (shapeType == '0') {
            shapeContainer->shapes[i] = create_shape("sphere", inputFile);
        } else if (shapeType == '1') {
            shapeContainer->shapes[i] = create_shape("parallelepiped", inputFile);
        } else if (shapeType == '2') {
            shapeContainer->shapes[i] = create_shape("tetrahedron", inputFile);
        }
    }
}

void fill_container_random(container *shapeContainer) {
    int type;
    for (int i = 0; i < shapeContainer->size(); ++i) {
        type = rand() % 3;
        if (type == 0) {
            shapeContainer->shapes[i] = create_shape("sphere", nullptr);
        } else if (type == 1) {
            shapeContainer->shapes[i] = create_shape("parallelepiped", nullptr);
        } else if (type == 2) {
            shapeContainer->shapes[i] = create_shape("tetrahedron", nullptr);
        }
    }
}

void swap(shape **a, shape **b) {
    shape *tmp = *a;
    *a = *b;
    *b = tmp;
}

int partition(container *arr, int low, int high) {
    shape *pivot = arr->shapes[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++) {
        if (arr->shapes[j]->calculate_surface_area() < pivot->calculate_surface_area()) {
            i++;
            swap(&(arr->shapes[i]), &(arr->shapes[j]));
        }
    }
    swap(&(arr->shapes[i + 1]), &(arr->shapes[high]));
    return (i + 1);
}

void sort(container *arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        sort(arr, low, pi - 1);
        sort(arr, pi + 1, high);
    }
}

container::~container() {
    for (int i = 0; i < containerSize; ++i) {
        sphere *pSphere = dynamic_cast<sphere *>(shapes[i]);
        tetrahedron *pTetra = dynamic_cast<tetrahedron *>(shapes[i]);
        parallelepiped *pParall = dynamic_cast<parallelepiped *>(shapes[i]);

        if (pSphere != nullptr) {
            delete pSphere;
        }

        if (pTetra != nullptr) {
            delete pTetra;
        }

        if (pParall != nullptr) {
            delete pParall;
        }
    }

    delete[] shapes;
}
