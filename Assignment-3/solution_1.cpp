//
// Created on Dec 14 2022; 19:24
// File: solution_1.cpp
//

#include <iostream>

// Recursive equation for subset sum problem:
// S(size, sum) = S(size-1, sum) || S(size-1, sum - array[n])

// Subset Sum Problem using Recursion
bool solutionRecursion(int *array, int size, int targetSum) {
    // Base case
    if (targetSum == 0)
        return true;
    if (size == 0)
        return false;

    // Recursive case
    // If the last element is greater than the target sum, then ignore it
    if (array[size - 1] > targetSum) {
        return solutionRecursion(array, size - 1, targetSum);
    }

    // If the last element is less than or equal to the target sum,
    // then check if the target sum can be obtained by including the last element or excluding the last element
    return solutionRecursion(array, size - 1, targetSum) ||
           solutionRecursion(array, size - 1, targetSum - array[size - 1]);
}


// Subset sum problem using Dynamic Programming
bool solutionDynamicProgramming(const int *array, int size, int targetSum) {
    // Create the matrix
    bool sumMatrix[size + 1][targetSum + 1];

    // Populate the matrix: 1st row and 1st column
    for (int i = 0; i <= size; ++i)
        sumMatrix[i][0] = true;
    for (int j = 1; j <= targetSum; ++j)
        sumMatrix[0][j] = false;

    // Populate the matrix: remaining cells
    for (int i = 1; i < size + 1; ++i) {
        for (int j = 1; j < targetSum + 1; ++j) {
            if (j < array[i])
                sumMatrix[i][j] = sumMatrix[i - 1][j];
            else {
                sumMatrix[i][j] = sumMatrix[i - 1][j] || sumMatrix[i - 1][j - array[i]];
            }
        }
    }

    // Backtrack to find the subset
    int backtrack[size], k = 0;
    for (int i = 0; i < size; ++i) {
        backtrack[i] = 0;
    }

    // If the target sum is possible, then backtrack to find the subset
    if (sumMatrix[size][targetSum]) {
        int i = size, j = targetSum, choice1i, choice1j, choice2i, choice2j;

        // Backtrack until the first row or column is reached
        while (i > 0 && j > 0) {
            choice1i = i - 1, choice1j = j;
            if (sumMatrix[choice1i][choice1j]) {
                i = choice1i;
                j = choice1j;
            } else {
                choice2i = i - 1, choice2j = j - array[i];
                if (sumMatrix[choice2i][choice2j]) {
                    backtrack[k] = array[i];
                    i = choice2i;
                    j = choice2j;
                    k++;
                }
            }
        }

        // Print the result
        std::cout << targetSum << " is a subset sum" << std::endl;
        for (int l = 0; l < k; ++l) {
            if (l == k - 1)
                std::cout << backtrack[l] << " = ";
            else
                std::cout << backtrack[l] << " + ";
        }
        std::cout << targetSum;
        return true;
    }
    return false;
}

int main(int argc, char **argv) {
    // Taking user input: Array Size
    int size;
    std::cin >> size;

    // Taking user input: Array elements
    int array[size];
    for (int i = 1; i <= size; ++i) {
        std::cin >> array[i];
    }

    // Taking user input: Target Sum
    int targetSum;
    std::cin >> targetSum;

    // Calling the function: Dynamic Programming
    solutionDynamicProgramming(array, size, targetSum);

    // Calling the function: Recursion
    // solutionRecursion(array, size, targetSum);

    return 0;
}
