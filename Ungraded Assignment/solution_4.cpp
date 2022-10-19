#include <iostream>

#define ARRAY_SIZE 1024

typedef struct {
    int element[ARRAY_SIZE];
    int size;
} Array;

void numberOfElements(Array *array) {
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
            // the last element resides in array->element[i]
            // So, we reiterate the array from index 0 to i and count the marked element.
            int count = 1;
            for (int j = 0; j < i; ++j)
                if (array->element[j] == array->element[i]) ++count;

            std::cout << array->element[i] << " occurs " << count << " times" << std::endl;
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
    numberOfElements(&array);

    return 0;
}