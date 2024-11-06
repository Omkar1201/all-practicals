#include <algorithm>
#include <iostream>
using namespace std;

// A structure to represent a job
struct Job {
    char id;    // Job ID
    int dead;   // Deadline of the job
    int profit; // Profit if job is completed before or on the deadline
};

// Comparator function for sorting jobs by profit in descending order
bool comparison(Job a, Job b) {
    return (a.profit > b.profit);
}

// Function to find the maximum profit job sequence
void printJobScheduling(Job arr[], int n) {
    // Sort all jobs in descending order of profit
    sort(arr, arr + n, comparison);

    int result[n];    // Array to store the result (sequence of job indices)
    bool slot[n];     // Array to keep track of occupied time slots
    int totalProfit = 0; // Variable to accumulate the total profit

    // Initialize all slots to be free
    for (int i = 0; i < n; i++) {
        slot[i] = false;
    }

    // Iterate through all given jobs
    for (int i = 0; i < n; i++) {
        // Find a free slot for this job (starting from the last possible slot)
        for (int j = min(n, arr[i].dead) - 1; j >= 0; j--) {
            // If a free slot is found
            if (slot[j] == false) {
                result[j] = i;         // Add this job to the result sequence
                slot[j] = true;        // Mark this slot as occupied
                totalProfit += arr[i].profit; // Add profit to totalProfit
                break;
            }
        }
    }

    // Print the job sequence
    cout << "Scheduled Jobs: ";
    for (int i = 0; i < n; i++) {
        if (slot[i]) {
            cout << arr[result[i]].id << " ";
        }
    }
    cout << "\nTotal Profit: " << totalProfit << endl;
}

// Driver's code
int main() {
    Job arr[] = { {'a', 2, 100},
                  {'b', 3, 19},
                  {'c', 2, 27},
                  {'d', 1, 50},
                  {'e', 3, 15} };

    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Following is the maximum profit sequence of jobs:\n";

    // Function call
    printJobScheduling(arr, n);
    return 0;
}
