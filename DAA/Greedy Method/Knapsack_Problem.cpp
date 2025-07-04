#include <stdio.h>

#define MAX_ITEMS 100
#define MAX_WEIGHT 100

// Function to get the maximum of two numbers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Knapsack function
int knapsack(int W, int wt[], int val[], int n) {
    int dp[n + 1][W + 1];

    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (i == 0 || w == 0)
                dp[i][w] = 0;
            else if (wt[i - 1] <= w)
                dp[i][w] = max(val[i - 1] + dp[i - 1][w - wt[i - 1]], dp[i - 1][w]);
            else
                dp[i][w] = dp[i - 1][w];
        }
    }

    return dp[n][W];
}

// Main function
int main() {
    int val[] = {60, 100, 120};
    int wt[] = {10, 20, 30};
    int W = 50;
    int n = sizeof(val) / sizeof(val[0]);

    printf("Maximum value in Knapsack: %d\n", knapsack(W, wt, val, n));
    return 0;
}

/*
Algorithm: 0/1 Knapsack using Dynamic Programming

1. Create a 2D array `dp[n+1][W+1]` where:
   - `n` is the number of items.
   - `W` is the maximum capacity of the knapsack.
   - `dp[i][w]` represents the maximum value that can be obtained with the first `i` items and a knapsack capacity `w`.

2. Initialize the first row and first column of the table with 0.
   - This represents the case when either there are no items or knapsack capacity is 0.

3. Fill the table in a bottom-up manner:
   For each item `i` from 1 to n:
      For each capacity `w` from 1 to W:
         a. If the weight of the current item `wt[i-1]` is less than or equal to `w`:
            - Include the item: `val[i-1] + dp[i-1][w - wt[i-1]]`
            - Exclude the item: `dp[i-1][w]`
            - Take the maximum of the above two.
         b. If `wt[i-1] > w`:
            - Cannot include the item, so `dp[i][w] = dp[i-1][w]`

4. After the table is completely filled, the result will be in `dp[n][W]`.

5. Return `dp[n][W]` as the maximum value that can be stored in the knapsack.
*/
