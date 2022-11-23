//
// Created on Nov 13 2022; 20:10
// File: solution_1.cpp
//

#include <iostream>
#include <vector>


// Struct to hold the items details
typedef struct {
    std::string name;
    double value;
    double weight;
} Box;

// Comparator for sorting Item according to value/weight ratio
bool sort_by_value_per_weight(const Box &b1, const Box &b2) {
    return (b1.value / b1.weight) > (b2.value / b2.weight);
}

// Knapsack function
double fractional_knapsack(double Weight, std::vector<Box> &boxes) {
    // Sort Item on basis of value per unit weight.
    std::sort(boxes.begin(), boxes.end(), sort_by_value_per_weight);

    // Initialize current weight and value
    double capacityLeft = Weight;
    double profit = 0;

    // Loop until all items are processed, capacity becomes 0, and box has value greater than 0
    for (int i = 0; capacityLeft > 0 && i < boxes.size() && boxes[i].weight > 0; ++i) {
        // If adding current item won't overflow, add it completely
        if (capacityLeft >= boxes[i].weight) {
            // Add current item completely;
            profit = profit + boxes[i].value;
            // Update capacity
            capacityLeft = capacityLeft - boxes[i].weight;

            // Print details after adding
            std::cout << "Taking " << boxes[i].name << ": "
                      << boxes[i].weight << " kg "
                      << boxes[i].value << " taka" << std::endl;

            // Update vector
            boxes[i].value = 0;
        }
            // if adding current boxes overflow then add fractional parts of it
        else {
            // Profit of adding fractional part of current item
            double takenProfit = (boxes[i].value / boxes[i].weight) * capacityLeft;
            // Add fractional part of current item
            profit = profit + takenProfit;

            // Print details after adding
            std::cout << "Taking " << boxes[i].name << ": \t"
                      << capacityLeft << " kg \t"
                      << (boxes[i].value / boxes[i].weight) * capacityLeft << " taka" << std::endl;

            // Update vector
            boxes[i].weight = boxes[i].weight - capacityLeft;
            boxes[i].value = boxes[i].value - takenProfit;
            // Update capacity
            capacityLeft = 0;

        }
    }
    return profit;

}

// Driver Code
int main(int argc, char **argv) {
    // Taking user input: number of boxes
    int entries;
    std::cin >> entries;

    // Vector data structure for holding all box information
    std::vector<Box> boxes;

    // Taking user input: Populate vector with box information
    for (int i = 0; i < entries; i++) {
        Box box{};
        std::cin >> box.name >> box.value >> box.weight;
        boxes.push_back(box);
    }

    // Taking user input: number of thief

    // Array for holding thief's knapsack weight
    int thief;
    std::cin >> thief;
    double knapsackOfThief[thief];
    for (int i = 0; i < thief; i++) {
        std::cin >> knapsackOfThief[i];
    }

    // Calculate profit for each thief
    for (int i = 0; i < thief; i++) {
        double profit = fractional_knapsack(knapsackOfThief[i], boxes);
        std::cout << "Thief " << i + 1 << " profit: " << profit << " taka" << std::endl;
        std::cout << std::endl;
    }

    std::cout << "Total " << thief << " thieves stole from that warehouse. " << std::endl;
    std::cout << "Still following items are left" << std::endl;
    for (int i = 0; i < boxes.size(); i++) {
        if (boxes[i].value > 0) {
            std::cout << boxes[i].name << " " << boxes[i].weight << " kg " << boxes[i].value  << " taka" << std::endl;
        }
    }

    return 0;
}

