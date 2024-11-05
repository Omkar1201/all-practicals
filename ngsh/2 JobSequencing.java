import java.util.Arrays;
import java.util.Comparator;

class Job {
    char id;
    int deadline;
    int profit;

    public Job(char id, int deadline, int profit) {
        this.id = id;
        this.deadline = deadline;
        this.profit = profit;
    }
}

public class JobSequencing {
    public static void printJobSequence(Job[] jobs) {
        // Sort jobs in descending order of profit
        Arrays.sort(jobs, new Comparator<Job>() {
            @Override
            public int compare(Job j1, Job j2) {
                return Integer.compare(j2.profit, j1.profit);
            }
        });

        int n = jobs.length;
        // Find the maximum deadline
        int maxDeadline = 0;
        for (Job job : jobs) {
            if (job.deadline > maxDeadline) {
                maxDeadline = job.deadline;
            }
        }

        // Initialize result array and slot array
        char[] result = new char[maxDeadline];
        boolean[] slot = new boolean[maxDeadline];

        // Fill result array with 'X' and slot array with false
        Arrays.fill(result, 'X');
        Arrays.fill(slot, false);

        // Iterate through all jobs
        for (int i = 0; i < n; i++) {
            // Find a free slot for this job (we start from the last possible slot)
            for (int j = Math.min(maxDeadline - 1, jobs[i].deadline - 1); j >= 0; j--) {
                if (!slot[j]) {
                    result[j] = jobs[i].id;
                    slot[j] = true;
                    break;
                }
            }
        }

        // Print the result
        System.out.print("Job Sequence: ");
        for (char jobId : result) {
            if (jobId != 'X') {
                System.out.print(jobId + " ");
            }
        }
        System.out.println();

        // Calculate and print the total profit
        int totalProfit = 0;
        for (int i = 0; i < maxDeadline; i++) {
            if (slot[i]) {
                for (Job job : jobs) {
                    if (job.id == result[i]) {
                        totalProfit += job.profit;
                        break;
                    }
                }
            }
        }
        System.out.println("Total Profit: " + totalProfit);
    }

    public static void main(String[] args) {
        Job[] jobs = {
            new Job('a', 2, 100),
            new Job('b', 1, 19),
            new Job('c', 2, 27),
            new Job('d', 1, 25),
            new Job('e', 3, 15)
        };

        System.out.println("Job Sequencing with Deadlines:");
        printJobSequence(jobs);
    }
}


/*
Sure! Here’s a simple breakdown of the job sequencing code:

### Overview
The program schedules jobs to maximize profit while respecting their deadlines. It takes a list of jobs, each with an ID, deadline, and profit, and outputs the sequence of jobs that can be completed within their deadlines along with the total profit.

### Code Breakdown

1. **Input Data**:
   - The program uses three arrays:
     - `jobIds`: Contains the IDs of the jobs (e.g., 'a', 'b', 'c').
     - `deadlines`: Contains the deadlines for each job (the latest time each job can be completed).
     - `profits`: Contains the profit for completing each job.

2. **Creating a Job Array**:
   - A 2D array called `jobs` is created to hold job details, where each job's profit, deadline, and original index are stored together.

3. **Sorting Jobs**:
   - The jobs are sorted in descending order based on their profit using `Arrays.sort()` and a `Comparator`. This means the job with the highest profit is considered first.

4. **Finding Maximum Deadline**:
   - The program finds the maximum deadline among all jobs to determine the size of the result array.

5. **Initializing Arrays**:
   - Two arrays are created:
     - `result`: Holds the sequence of jobs that will be completed.
     - `slot`: Keeps track of which time slots are filled (true if a job is scheduled in that slot).

6. **Job Scheduling**:
   - The program iterates through each job and tries to find the latest available time slot (from the job's deadline backward). If a free slot is found, the job is scheduled in that slot.

7. **Printing Results**:
   - After scheduling, the program prints the job sequence that can be completed before their deadlines.
   - It then calculates and prints the total profit from the scheduled jobs.

### Example
For the input:
- Jobs: `{'a', 'b', 'c', 'd', 'e'}`
- Deadlines: `{2, 1, 2, 1, 3}`
- Profits: `{100, 19, 27, 25, 15}`

The output would be:
- **Job Sequence**: `a c e` (jobs that can be completed within their deadlines)
- **Total Profit**: `142` (the total profit from these jobs)

### Summary
This program efficiently schedules jobs to maximize profits while ensuring each job is completed before its deadline, using sorting and simple data structures.
 */