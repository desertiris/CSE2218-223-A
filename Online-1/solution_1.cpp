// Created on Sun Nov 6 10:10

#include <iostream>

// Function for calculating the GCD recursively
int gcd(int x, int y) {
    // Base case
    if(x == 0) return y;
    // Recursive case
    else return gcd(y % x, x);
}

int main(int argc, char **argv) {
    // Taking user input: Two numbers
    int x, y;
    std::cin >> x >> y;

    // Calculating the GCD of two numbers
    std::cout << "The GCD of (" << x << ", " << y << ") is: " << gcd(x,y) << std::endl;
}