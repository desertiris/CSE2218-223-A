//
// Created on Nov 14 2022; 01:30
// File: solution_2.cpp
//

#include <iostream>

void calculate_lowest_gasStop(const int *gasStops, int distance, int tankCapacity, int gasStopsSize) {
    // Variable for holding the current gas tank capacity
    int currentTankCapacity = tankCapacity;

    // Iterate through the gas stops
    for (int i = 0; i < gasStopsSize; ++i) {
        // Check if the gas stop is within the tank capacity
        if (gasStops[i] <= currentTankCapacity) continue;
        else if (gasStops[i] > distance) break;
        // If not, update the current tank capacity
        else {
            // Update the current tank capacity
            currentTankCapacity = tankCapacity + gasStops[i - 1];
            // Print the gas stop
            std::cout << "stop at gas station " << i << " ( "
                      << gasStops[i - 1] << " miles)" << std::endl;
        }
    }
}


// Driver code
int main(int argc, char **argv) {
    // Getting user input: total distance
    int totalDistance;
    std::cin >> totalDistance;

    // Getting user input: travel distance with full tank
    int fullTankDistance;
    std::cin >> fullTankDistance;

    // Getting user input: number of gas station
    int gasStation;
    std::cin >> gasStation;

    // Vector for holding gas station distance
    int gasStationDistance[gasStation];
    // Populate vector with gas station distance
    for (int i = 0; i < gasStation; i++) {
        int distance;
        std::cin >> distance;
        gasStationDistance[i] = distance;
    }

    // Calculate the number of gas stops
    calculate_lowest_gasStop(gasStationDistance, totalDistance,
                             fullTankDistance, gasStation);


    return 0;
}
