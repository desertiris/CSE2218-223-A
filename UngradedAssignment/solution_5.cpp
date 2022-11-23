#include <iostream>

// Optimize the inputs
void optimizeInputs(int *number1, int *number2) {
    if (*number1 > *number2) {
        int temp = *number1;
        *number1 = *number2;
        *number2 = temp;
    } else return;
}

int calc_factorial(int number) {
    int factorial = 1;
    for (int i = 1; i <= number; ++i) {
        factorial *= i;
    }
    return factorial;
}

int main() {
    int number1, number2;
    std::cin >> number1 >> number2;
    optimizeInputs(&number1, &number2);

    for (int i = number1; i <= number2; ++i) {
        std::cout << i << "! = ";
        for (int j = i; j > 0; --j) {
            std::cout << j;
            if (j != 1) std::cout << " * ";
        }
        std::cout << " = " << calc_factorial(i) << std::endl;
    }

    return 0;
}