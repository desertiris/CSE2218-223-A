//
// Created on Nov 10 2022; 08:09
// File: solution_2.cpp
//

#include <iostream>
#include <string>

// Function to determine if a number is prime
bool isPalindrome(std::string string) {
    // Base Case
    if (string.length() <= 1) return true;

    // Recursive Case
    else {
        if (string[0] == string[string.length() - 1]) {
            return isPalindrome(string.substr(1, string.length() - 2));
        }
        return false;
    }
}

// Function for calculate palindromes in given range and print them with their sum
void sum_palindrome(int start, int end, int sum) {
    // Base Case
    if (start == end) {
        std::cout << std::endl;
        std::cout << "sum " << sum << std::endl;
    }

    // Recursive Case
    else {
        if (isPalindrome(std::to_string(start))) {
            sum = sum + start;
            std::cout << start << " ";
        }
        return sum_palindrome(start + 1, end, sum);
    }
}

// Driver Code
int main(int argc, char **argv) {
    // Taking user input: range;
    int start, end, sum = 0;
    std::cin >> start >> end;

    // Perform operation
    sum_palindrome(start, end, sum);
    return 0;
}