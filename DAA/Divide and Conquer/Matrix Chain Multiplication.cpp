#include <stdio.h>
#include <limits.h>

// Function to find the minimum number of scalar multiplications needed
int matrixChainOrder(int p[], int n) {
    int m[n][n];
    
    for (int i = 1; i < n; i++)
        m[i][i] = 0;
    
    for (int L = 2; L < n; L++) {
        for (int i = 1; i < n - L + 1; i++) {
            int j = i + L - 1;
            m[i][j] = INT_MAX;
            for (int k = i; k < j; k++) {
                int q = m[i][k] + m[k+1][j] + p[i-1] * p[k] * p[j];
                if (q < m[i][j])
                    m[i][j] = q;
            }
        }
    }
    return m[1][n-1];
}

int main() {
    int arr[] = {1, 2, 3, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Minimum number of multiplications is %d\n", matrixChainOrder(arr, n));
    return 0;
}

/*
Algorithm: Matrix Chain Multiplication (Dynamic Programming)

1. Given an array `p[]` of dimensions where the ith matrix has dimensions p[i-1] x p[i].

2. Let m[i][j] represent the minimum number of scalar multiplications needed to compute the product of matrices from i to j.

3. Initialize m[i][i] = 0 for all i, since multiplying one matrix requires zero multiplications.

4. Loop L from 2 to n-1 (L is the chain length):
    a. For each i from 1 to n-L:
        i. Set j = i + L - 1
        ii. Initialize m[i][j] = ∞ (INT_MAX)
        iii. Loop k from i to j-1:
            - Compute cost of splitting the chain at k:
              q = m[i][k] + m[k+1][j] + p[i-1] * p[k] * p[j]
            - If q < m[i][j], update m[i][j] = q

5. After filling the table, m[1][n-1] will contain the minimum number of scalar multiplications needed.

6. Return m[1][n-1] as the final answer.
*/
