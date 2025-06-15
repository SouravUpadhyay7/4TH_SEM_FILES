#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id, deadline, profit;
} Job;

int compare(const void *a, const void *b) {
    return ((Job *)b)->profit - ((Job *)a)->profit;
}

// Function to find maximum profit job sequence
void jobSequencing(Job jobs[], int n) {
    qsort(jobs, n, sizeof(Job), compare);

    int maxDeadline = 0;
    for (int i = 0; i < n; i++)
        if (jobs[i].deadline > maxDeadline)
            maxDeadline = jobs[i].deadline;

    int result[maxDeadline + 1]; 
    for (int i = 0; i <= maxDeadline; i++)
        result[i] = -1;

    int totalProfit = 0;

    for (int i = 0; i < n; i++) {
        for (int j = jobs[i].deadline; j > 0; j--) {
            if (result[j] == -1) {
                result[j] = jobs[i].id;
                totalProfit += jobs[i].profit;
                break;
            }
        }
    }

    printf("Job sequence: ");
    for (int i = 1; i <= maxDeadline; i++)
        if (result[i] != -1) printf("%d ", result[i]);

    printf("\nTotal Profit: %d\n", totalProfit);
}

// Main function
int main() {
    Job jobs[] = {{1, 2, 100}, {2, 1, 50}, {3, 2, 10}, {4, 1, 20}, {5, 3, 30}};
    int n = sizeof(jobs) / sizeof(jobs[0]);

    jobSequencing(jobs, n);
    return 0;
}

/*
Algorithm: Job Sequencing to Maximize Profit

1. Sort all jobs in descending order of their profit.

2. Find the maximum deadline among all jobs to determine the number of available time slots.

3. Create a result array of size (maxDeadline + 1) and initialize all slots to -1 to represent free time slots.

4. Initialize totalProfit to 0.

5. For each job in the sorted list:
   a. Try to schedule the job in the latest possible free slot before its deadline.
   b. Start checking from the job's deadline down to 1.
   c. If a free slot is found:
      - Assign the job to that slot.
      - Add the job's profit to totalProfit.
      - Break out of the inner loop (move to the next job).

6. After processing all jobs, the result array contains the job sequence that yields maximum profit.

7. Print the job IDs in the sequence and the total profit earned.
*/
