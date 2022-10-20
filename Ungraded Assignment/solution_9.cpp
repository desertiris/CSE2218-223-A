#include <iostream>

// Structure for Employee
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
void sort(Employee *employee, size_t size) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (employee[j].height < employee[j + 1].height) {
                Employee temp = employee[j];
                employee[j] = employee[j + 1];
                employee[j + 1] = temp;
            } else if (employee[j].height == employee[j + 1].height) {
                if (employee[j].age < employee[j + 1].age) {
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
    Employee employees[entry];

    // Input employee details
    for (int i = 0; i < entry; ++i) {
        fflush(stdin);
        fgets(employees[i].name, 100, stdin);
        std::cin >> employees[i].height;
        std::cin >> employees[i].age;
    }

    // Sort the employees
    sort(employees, entry);

    // Print the employees
    printEmployees(employees, entry);

    return 0;
}