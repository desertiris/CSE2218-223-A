#include <iostream>

void toggleCase(char *string) {
    for (int i = 0; string[i] != '\0'; ++i) {
        if (string[i] >= 'A' && string[i] <= 'Z') {
            string[i] += 32;
        } else if (string[i] >= 'a' && string[i] <= 'z') {
            string[i] -= 32;
        }
    }

}

int main() {
    // Input string
    char string[100];
    fgets(string, 100, stdin);

    // Toggle the case
    toggleCase(string);

    // Print the string
    std::cout << string;
    return 0;
}