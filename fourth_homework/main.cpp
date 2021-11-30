#include "iostream"
#include "shapes/shape.h"
#include "shapes/sphere.h"
#include "shapes/parallelepiped.h"
#include "shapes/tetrahedron.h"
#include "ctime"

class container {
    int containerSize;
public:
    shape **shapes;

    container(int size);

    ~container();

    int size();

};

void fill_container(container *shapeContainer, FILE *inputFile);

void fill_container_random(container *shapeContainer);

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


void print_error(char *message) {
    printf("\e[31m[ERROR]\e[0m %s\n", message);
}

void print_success(char *message) {
    printf("\e[92m[SUCCESS]\e[0m %s\n", message);
}

void print_warning(char *message) {
    printf("\e[93m[WARNING]\e[0m %s\n", message);
}


int main(int argc, char *argv[]) {
    srand((unsigned) time(nullptr));

    int containerSize;
    char typeOfInput;


    if (argc != 3) {
        print_error("Wrong parameters!");
        return 1;
    }

    char *in = argv[1];
    char *out = argv[2];

    FILE *inputFile = fopen(in, "r");
    FILE *outputFile = fopen(out, "w");

    if (inputFile == nullptr) {
        print_error("File was not found");
        return 1;
    }

    print_success("Reading file...");
    fscanf(inputFile, "%c %d\n", &typeOfInput, &containerSize);
    container *shapeContainer = new container(containerSize);

    if (typeOfInput == 'r') {
        fill_container_random(shapeContainer);
    } else if (typeOfInput == 'm') {
        fill_container(shapeContainer, inputFile);
    } else {
        print_error("Wrong type of input!");
        return 1;
    }

    sort(shapeContainer, 0, containerSize - 1);
    fprintf(outputFile, "%d\n", containerSize);
    for (int i = 0; i < shapeContainer->size(); ++i) {
        shapeContainer->shapes[i]->to_string(outputFile);
        shapeContainer->shapes[i]->to_string();
    }

    print_warning("Finalizing program...");
    delete shapeContainer;
    fclose(inputFile);
    fclose(outputFile);

    print_success("Done!");
}
