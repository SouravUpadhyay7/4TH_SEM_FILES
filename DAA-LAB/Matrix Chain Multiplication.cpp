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

