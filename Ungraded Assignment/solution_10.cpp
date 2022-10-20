#include <iostream>

typedef struct {
    char name[100];
    double height;
    int age;
} Employee;

// Function for printing the employee details
void printEmployees(Employee *employees, int size) {
    for (int i = 0; i < size; ++i) {
        std::cout << employees[i].name;
        std::cout << employees[i].height << " ";
        std::cout << employees[i].age << " ";
        std::cout << std::endl;
    }
}

// Function for sorting the employees by height, if height is same then sort by age
// Sort in Ascending order
void sort(Employee *employee, size_t size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (employee[j].height > employee[j + 1].height) {
                Employee temp = employee[j];
                employee[j] = employee[j + 1];
                employee[j + 1] = temp;
            } else if (employee[j].height == employee[j + 1].height) {
                if (employee[j].age > employee[j + 1].age) {
                    Employee temp = employee[j];
                    employee[j] = employee[j + 1];
                    employee[j + 1] = temp;
                }
            }
        }
    }
}

int main() {
    // Input number of employees
    int entry;
    std::cin >> entry;

    // Create three arrays for name, height and age
    char names[entry][100];
    double heights[entry];
    int ages[entry];

    // Input employee names
    for (int i = 0; i < entry; ++i) {
        fflush(stdin);
        fgets(names[i], 100, stdin);
    }

    // Input employee ages
    for (int i = 0; i < entry; ++i) {
        std::cin >> ages[i];
    }

    // Input employee heights
    for (int i = 0; i < entry; ++i) {
        std::cin >> heights[i];
    }

    // Assign the values to the structure
    Employee employees[entry];
    for (int i = 0; i < entry; ++i) {
        strcpy(employees[i].name, names[i]);
        employees[i].height = heights[i];
        employees[i].age = ages[i];
    }

    // Sort the employees
    sort(employees, entry);

    // Print the employees
    printEmployees(employees, entry);

    return 0;
}