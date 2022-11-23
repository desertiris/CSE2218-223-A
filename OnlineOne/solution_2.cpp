// Created on Sun Nov 6 10:10

#include <iostream>

int main(int argc, char **argv) {
    int sum = 0;    // variable for tracking summation

    // Taking user input: number of entries
    int entries;
    std::cin >> entries;
    // Array for storing entries
    int *array = new int[entries];

    // Taking user input: entries
    for (int i = 0; i < entries; ++i) {
        std::cin >> array[i];
    }

    // Print all the digits and Calculate summation of good numbers
    for (int i = 0; i < entries; ++i) {
        // Calculation of summation of good numbers
        if(array[i] % 11 == 0) sum = sum + array[i];

        // Printing all the numbers
        std::cout << array[i] << "\t";

        // Printing Summation of good numbers
        if(i == entries - 1) {
            std::cout << std::endl;
            std::cout << "Summation of good numbers: " << sum << std::endl;
        }
    }

    return 0;
}