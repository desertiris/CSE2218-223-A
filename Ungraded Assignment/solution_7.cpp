#include <iostream>

// Function for converting every alphabetical character to lowercase
void conv_to_lower(char *string) {
    for (int i = 0; string[i] != '\0'; ++i) {
        if (string[i] >= 'A' && string[i] <= 'Z') {
            string[i] += 32;
        }
    }
}

// Function for removing whitespaces
void remove_ws(char *string) {
    for (int i = 0; string[i] != '\0'; ++i) {
        if (string[i] == ' ') {
            for (int j = i; string[j] != '\0'; ++j) {
                string[j] = string[j + 1];
            }
        }
    }
}

int main() {
    // Input string
    char string[100];
    fgets(string, 100, stdin);

    // Convert to lowercase
    conv_to_lower(string);

    // Remove whitespaces
    remove_ws(string);

    // Print the string
    std::cout << string;
}