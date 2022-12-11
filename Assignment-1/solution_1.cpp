//
// Created on Nov 10 2022; 08:09
// File: solution_1.cpp
//

#include <iostream>

// Function to determine if a number is prime
bool isPrime(int n) {
    // If the number is less than 2, it is not prime
    if (n <= 1) return false;

    // If the number is divisible by 2 to n-1, it is not prime
    for (int i = 2; i < n; i++) {
        if (n % i == 0) return false;
    }

    // For all previous condition false, it is prime
    return true;
}

// Recursive function to print all prime numbers and their sum
void count_primes(int *array_start, const int *array_end, int count) {
    // Base Case
    if (array_start == array_end) {
        std::cout << std::endl;
        std::cout << "#primes=" << count;
    }

    // Recursive Case
    else {
        if (isPrime(*array_start)) {
            ++count;
            std::cout << *array_start << " ";
        }
        return count_primes(array_start + 1, array_end, count);
    }
}


// Driver code
int main() {
    // Taking user input: number of entries
    size_t entries;
    std::cin >> entries;

    // Taking user input: entries
    int *array = new int[entries];
    for (int i = 0; i < entries; ++i) {
        std::cin >> array[i];
    }

    // Counting primes
    count_primes(array, array + entries, 0);

    return 0;
}
