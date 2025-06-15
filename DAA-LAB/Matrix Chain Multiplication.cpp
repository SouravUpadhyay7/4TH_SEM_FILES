#include <stdio.h>
#include <limits.h>

int matrixChainOrder(int p[], int n) {
    int m[n][n];

    // m[i][j] = Minimum number of multiplications needed to compute A[i]...A[j]
    for (int i = 1; i < n; i++)
        m[i][i] = 0;

    for (int chain_len = 2; chain_len < n; chain_len++) {
        for (int i = 1; i < n - chain_len + 1; i++) {
            int j = i + chain_len - 1;
            m[i][j] = INT_MAX;

            for (int k = i; k < j; k++) {
                int cost = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];
                if (cost < m[i][j])
                    m[i][j] = cost;
            }
        }
    }

    return m[1][n-1];
}

int main() {
    int dimensions[] = {40, 20, 30, 10, 30};
    int n = sizeof(dimensions) / sizeof(dimensions[0]);

    int minMultiplications = matrixChainOrder(dimensions, n);
    printf("Minimum number of multiplications: %d\n", minMultiplications);

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
