//
// Created on Dec 14 2022; 19:25
// File: solution_2.cpp
//

#include <iostream>

// Naive recursive method
int solutionNaive(int *array, int size) {
    if (size == 0) return 0;
    int profit = 0;
    for (int i = 1; i <= size; ++i) {
        profit = std::max(profit, array[i] + solutionNaive(array, size - i));
    }
    return profit;
}

// Dynamic Programming method
void solutionDynamicProgramming(const int* array, int size){
    // Create the matrix
    int matrix[size + 1];

    // Create solution matrix
    int solution[size + 1];

    // Populate the Matrix
    matrix[0] = 0;
    for (int i = 1; i <= size; ++i) {
        int income = -1;
        for (int j = 1; j <= i; ++j) {
            if (income < array[j] + matrix[i - j]){
                income = array[j] + matrix[i - j];
                solution[i] = j;
            }
        }
        matrix[i] = income;
    }
    // Printing Maximum income
    std:: cout << "income: " << matrix[size] << " taka"<< std:: endl;

    // Printing the solution
    while (size > 0){
        std::cout << solution[size] << " piece together " << matrix[solution[size]] << " taka" << std::endl;
        size = size - solution[size];
    }
}

int main() {
    // Taking user input: cake length
    int rodLength;
    std::cin >> rodLength;

    // Taking user input: Price of each cake length
    int arrayPrice[rodLength+1];
    for (int i = 1; i <= rodLength; ++i) {
        std::cin >> arrayPrice[i];
    }

    // Calling the function: Naive Recursion
    // solutionNaive(arrayPrice, rodLength);

    // Calling the function: Tabular Method
    solutionDynamicProgramming(arrayPrice, rodLength);

}
