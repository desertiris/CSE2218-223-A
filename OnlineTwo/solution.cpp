#include <iostream>
#include <vector>

// Structure to hold the Job Information
typedef struct {
    int jobID;
    int startTime;
    int duration;
    int difficulty;
} Job;

// comparator to sort the jobs based on the start time
bool sort_by_start_time(Job j1, Job j2) {
    return j1.startTime < j2.startTime;
}

// Function to calculate job schedules
void jobs_selection(std::vector<Job> jobs, int dayStartTime, int dayEndTime, int salary) {
    // Sort the jobs based on the start time
    std::sort(jobs.begin(), jobs.end(), sort_by_start_time);

    // Variable for holding occupied hours
    int occupiedHour = dayStartTime;

    // Variable for holding the total salary
    int earning = 0;

    // Iterate through the Vector
    for (Job &job: jobs)
        // Check if the job can be done withing given time range
        if (job.startTime < occupiedHour) {
            continue;
        }
            // If so, select the job and print the jobs information
        else {
            std::cout << "job" << job.jobID << " starts at " << job.startTime
                      << ", and ends at " << job.startTime + job.duration
                      << ", difficulty is " << job.difficulty << std::endl;

            // Update occupied hour
            occupiedHour = job.startTime + job.duration;
            // Update salary
            earning = earning + salary;

            // If occupied hour cross past given time range, exit the loop
            if (occupiedHour >= dayEndTime) break;
        }


    // Print Expected Earnings
    std::cout << "Expected earnings " << earning << " dollar";
}

// Driver Code
int main() {
    // Taking user input: number of jobs
    int entries;
    std::cin >> entries;

    // Vector data structure for holding all job information
    std::vector<Job> jobs;

    // Taking user input: start time, duration, difficulty
    for (int i = 0; i < entries; i++) {
        Job job;
        std::cin >> job.startTime >> job.duration >> job.difficulty;
        job.jobID = i + 1;
        jobs.push_back(job);
    }

    // Taking user input: salary
    int salary;
    std::cin >> salary;

    // Taking user input: Time range
    int A, B;
    std::cin >> A >> B;
    std::cout << "hello";

    jobs_selection(jobs, A, B, salary);


}
