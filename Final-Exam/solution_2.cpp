//
// Created by Shanta Biswas on Jan 01 2023; 09:01
// File: solution_2.cpp
//

#include <iostream>

int main(int argc, char **argv) {
    int numberOfBoxes;
    std::cin >> numberOfBoxes;

    int numberOfMoves;
    std::cin >> numberOfMoves;

    int chocolate[numberOfBoxes];

    for (int i = 0; i < numberOfBoxes; ++i) {
        std::cin >> chocolate[i];
    }

    // Sort the array descending
    for (int i = 0; i < numberOfBoxes; ++i) {
        for (int j = i + 1; j < numberOfBoxes; ++j) {
            if (chocolate[i] < chocolate[j]) {
                int temp = chocolate[i];
                chocolate[i] = chocolate[j];
                chocolate[j] = temp;
            }
        }
    }

    // Make Moves
    int maximumNumberOfChocolates = chocolate[0];
    for (int i = 0; i < numberOfMoves; ++i) {
        maximumNumberOfChocolates = maximumNumberOfChocolates + chocolate[i + 1];
    }

    // Printing Output
    std::cout << maximumNumberOfChocolates;

    return 0;
}
