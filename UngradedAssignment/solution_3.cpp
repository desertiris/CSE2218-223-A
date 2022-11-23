#include <iostream>

#define ARRAY_SIZE 1024

typedef struct {
    int element[ARRAY_SIZE];
    int size;
} Array;


// Find and print all the element once
void findUnique(Array *array) {
    for (int i = 0; i < array->size; ++i) {
        // check if this is the last occurrence of element[i]
        bool last = true;
        for (int j = i + 1; j < array->size; ++j) {
            if (array->element[i] == array->element[j]) {
                last = false;
                break;
            }
        }

        if (last) {
            std::cout << array->element[i] << " ";
        }
    }
}

int main() {
    // Create an element
    Array array;

    // Taking user input: Array Size
    int size;
    std::cin >> size;
    array.size = size;

    // Taking user input: Array Elements
    for (int i = 0; i < array.size; i++) {
        std::cin >> array.element[i];
    }

    // Find the Unique Elements
    findUnique(&array);

    return 0;
}