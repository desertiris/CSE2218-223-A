#include <iostream>
#include <iomanip>  // for setting double precision points

int main() {
    // Taking the number of entries
    int entry;
    double sum = 0;
    std::cin >> entry;

    // Taking the entries
    for (int i = 0; i < entry; ++i) {
        int number;
        std::cin >> number;
        sum += number;
    }

    // Printing the average
    std::cout << std::setprecision(4) << sum / entry << std::endl;

    return 0;
}