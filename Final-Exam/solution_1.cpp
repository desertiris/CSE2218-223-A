//
// Created by Shanta Biswas on Jan 01 2023; 08:59
// File: solution_1.cpp
//

#include <iostream>
#include <vector>

void dynamicSolution(int lengthOfCargo, int numberOfBoxes, std::vector<int> lengthOfBoxes) {

    // Create the matrix
    int matrix[lengthOfCargo + 1][numberOfBoxes + 1];

    int matrixX = lengthOfCargo + 1;
    int matrixY = numberOfBoxes + 1;

    // Fill the matrix using dynamic programming
    for (int i = 0; i < matrixX + 1; i++) {
        for (int j = 0; j < matrixY + 1; ++j) {

            // Fill matrix with 0s and 1s
            if (i == 0) matrix[i][j] = 1;
            else if (j == 0) matrix[i][j] = 0;

            // dynamically allocate matrix
            else if (lengthOfBoxes[j] <= i) {
                if (matrix[i - lengthOfBoxes[j]][j - 1] == 1) matrix[i][j] = 1;
                else matrix[i][j] = matrix[i][j - 1];
            }
            else matrix[i][j] = matrix[i][j - 1];
        }
    }

    if (matrix[lengthOfCargo][numberOfBoxes] == 1) {
        std::cout << "Yes" << std::endl;
    } else {
        std::cout << "No" << std::endl;
    }
}

int main() {
    int sizeOfCargo;
    std::cin >> sizeOfCargo;

    int numberOfBoxes;
    std::cin >> numberOfBoxes;

    std::vector<int> sizeOfEachBoxes;
    for (int i = 0; i < numberOfBoxes; ++i) {
        int coin;
        std::cin >> coin;
        sizeOfEachBoxes.push_back(coin);
    }

    dynamicSolution(sizeOfCargo, numberOfBoxes, sizeOfEachBoxes);

}

















