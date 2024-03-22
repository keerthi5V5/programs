#include <stdio.h>
#include <stdlib.h>

// Function to sort the processes based on arrival time
void sortProcesses(int *arrival, int *burst, int n) {
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arrival[j] > arrival[j + 1]) {
                // Sort arrival time
                temp = arrival[j];
                arrival[j] = arrival[j + 1];
                arrival[j + 1] = temp;
                // Sort burst time accordingly
                temp = burst[j];
                burst[j] = burst[j + 1];
                burst[j + 1] = temp;
            }
        }
    }
}

// Function to compute average waiting time and turnaround time
void computeTimes(int *arrival, int *burst, int n) {
    int currentTime = 0;
    int totalWaitingTime = 0, totalTurnaroundTime = 0;
    int remaining[n];
    // Initialize remaining time for all processes
    for (int i = 0; i < n; i++) {
        remaining[i] = burst[i];
    }

    // Process until all processes are completed
    while (1) {
        int smallestRemaining = -1;
        // Find the process with the smallest remaining burst time
        for (int i = 0; i < n; i++) {
            if (arrival[i] <= currentTime && remaining[i] > 0) {
                if (smallestRemaining == -1 || remaining[i] < remaining[smallestRemaining]) {
                    smallestRemaining = i;
                }
            }
        }
        // If no process is available at the current time, move to the next arrival time
        if (smallestRemaining == -1) {
            int nextArrival = 9999;
            for (int i = 0; i < n; i++) {
                if (arrival[i] > currentTime && arrival[i] < nextArrival) {
                    nextArrival = arrival[i];
                }
            }
            currentTime = nextArrival;
            continue;
        }

        // Execute the process with the smallest remaining burst time
        remaining[smallestRemaining]--;
        currentTime++;

        // If the process is completed
        if (remaining[smallestRemaining] == 0) {
            int completionTime = currentTime;
            int waitingTime = completionTime - arrival[smallestRemaining] - burst[smallestRemaining];
            int turnaroundTime = completionTime - arrival[smallestRemaining];

            totalWaitingTime += waitingTime;
            totalTurnaroundTime += turnaroundTime;
        }

        // If all processes are completed, break the loop
        if (currentTime >= 1000) { // Set an arbitrary large value as the end time
            break;
        }
    }

    // Calculate averages
    float avgWaitingTime = (float)totalWaitingTime / n;
    float avgTurnaroundTime = (float)totalTurnaroundTime / n;

    printf("Average Waiting Time: %.2f\n", avgWaitingTime);
    printf("Average Turnaround Time: %.2f\n", avgTurnaroundTime);
}

int main() {
    // Define processes' arrival and burst times
    int arrival[] = {0, 1, 2, 4};
    int burst[] = {5, 3, 3, 1};
    int n = sizeof(arrival) / sizeof(arrival[0]);

    // Sort processes based on arrival time
    sortProcesses(arrival, burst, n);

    // Compute average waiting time and turnaround time
    computeTimes(arrival, burst, n);

    return 0;
}

