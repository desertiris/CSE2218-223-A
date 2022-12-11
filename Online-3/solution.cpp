#include <iostream>

// Function of minimum number of boxes to fill the cargo using dynamic programming
void solution(int totalNumberOfBoxes, int *boxes, int cargoLength) {
    int *matrix = new int[cargoLength + 1];

    // Building Matrix
    matrix[0] = 0;
    for (int i = 1; i <= cargoLength; i++) {
        matrix[i] = -1;
        for (int j = 0; j < totalNumberOfBoxes; j++) {
            if (i - boxes[j] >= 0 && matrix[i - boxes[j]] != -1) {
                if (matrix[i] == -1 || matrix[i] > matrix[i - boxes[j]] + 1) {
                    matrix[i] = matrix[i - boxes[j]] + 1;
                }
            }
        }
    }

    // Printing the minimum number of boxes that are needed
    std::cout << "minimum " << matrix[cargoLength] << " boxes." << std::endl;

    // Printing which lengths of box(es) are needed
    while (cargoLength > 0) {
        for (int i = 0; i < totalNumberOfBoxes; i++) {
            if (cargoLength - boxes[i] >= 0 && matrix[cargoLength] == matrix[cargoLength - boxes[i]] + 1) {
                std::cout << boxes[i] << " meter" << std::endl;
                cargoLength = cargoLength - boxes[i];
                break;
            }
        }
    }
}

int main() {
    // Taking user input: Number of Boxes
    int totalNumberOfBoxes;
    std::cin >> totalNumberOfBoxes;

    // Taking user input: Boxes
    int boxes[totalNumberOfBoxes];
    for (int i = 0; i < totalNumberOfBoxes; ++i) {
        std::cin >> boxes[i];
    }

    // Taking user input: Length of cargo
    int cargoLength;
    std::cin >> cargoLength;

    // Printing the result
    solution(totalNumberOfBoxes, boxes, cargoLength);

}

/**
 * Sample Input---
 *
 * 5
 * 1 23 25 12 10
 * 46
 */
