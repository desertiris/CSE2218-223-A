#include <iostream>

int main() {
    // Input character
    char character;

    // Taking the character until input becomes 'A'
    while (true) {
        std::cin >> character;
        if (character != 'A') std::cout << character << std::endl;
        else break;
    }

    return 0;
}
