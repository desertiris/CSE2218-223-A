#include <iostream>

#define ARRAY_SIZE 1024

typedef struct {
    int element[ARRAY_SIZE];
    int size;
} Array;

// Print all the element of an array
void print_array(Array *array) {
    for (int i = 0; i < array->size; ++i) {
        std::cout << array->element[i] << " ";
    }
}

// Function to reverse the array
void reverse_array(Array *array) {
    for (int i = 0; i < array->size / 2; ++i) {
        int temp = array->element[i];
        array->element[i] = array->element[array->size - i - 1];
        array->element[array->size - i - 1] = temp;
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

    // Reverse the array
    reverse_array(&array);

    // print all elements
    print_array(&array);

    return 0;
}