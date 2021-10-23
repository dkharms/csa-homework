#include "iostream"

#include "container.h"
#include "ctime"

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
