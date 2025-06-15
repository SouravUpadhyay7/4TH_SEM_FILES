#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char id;
    int deadline;
    int profit;
} Job;

int compare(const void* a, const void* b) {
    return ((Job*)b)->profit - ((Job*)a)->profit;
}

int min(int a, int b) {
    return (a < b) ? a : b;
}

void jobScheduling(Job jobs[], int n) {
    qsort(jobs, n, sizeof(Job), compare);

    int maxDeadline = 0;
    for (int i = 0; i < n; i++)
        if (jobs[i].deadline > maxDeadline)
            maxDeadline = jobs[i].deadline;

    char schedule[maxDeadline];
    for (int i = 0; i < maxDeadline; i++)
        schedule[i] = '-';

    int totalProfit = 0;

    for (int i = 0; i < n; i++) {
        for (int j = min(maxDeadline, jobs[i].deadline) - 1; j >= 0; j--) {
            if (schedule[j] == '-') {
                schedule[j] = jobs[i].id;
                totalProfit += jobs[i].profit;
                break;
            }
        }
    }

    printf("Job sequence: ");
    for (int i = 0; i < maxDeadline; i++)
        if (schedule[i] != '-')
            printf("%c ", schedule[i]);
    printf("\nTotal profit: %d\n", totalProfit);
}

int main() {
    Job jobs[] = {
        {'a', 2, 100},
        {'b', 1, 19},
        {'c', 2, 27},
        {'d', 1, 25},
        {'e', 3, 15}
    };
    int n = sizeof(jobs) / sizeof(jobs[0]);

    jobScheduling(jobs, n);

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

