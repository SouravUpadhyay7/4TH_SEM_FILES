#include <stdio.h>
#define N 4

int board[N][N];

int isSafe(int row, int col) {
    // Check this row on left side
    for (int i = 0; i < col; i++)
        if (board[row][i])
            return 0;

    // Check upper diagonal on left side
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return 0;

    // Check lower diagonal on left side
    for (int i = row, j = col; j >= 0 && i < N; i++, j--)
        if (board[i][j])
            return 0;

    return 1;
}

int solveNQUtil(int col) {
    if (col >= N)
        return 1;

    for (int i = 0; i < N; i++) {
        if (isSafe(i, col)) {
            board[i][col] = 1;

            if (solveNQUtil(col + 1))
                return 1;

            board[i][col] = 0; // BACKTRACK
        }
    }

    return 0;
}

void printSolution() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            printf("%d ", board[i][j]);
        printf("\n");
    }
}

int main() {
    if (solveNQUtil(0) == 0) {
        printf("Solution does not exist\n");
    } else {
        printf("One of the solutions:\n");
        printSolution();
    }

    return 0;
}

/*
Algorithm: Solve N-Queens Problem using Backtracking

1. Problem Statement:
   - Place N queens on an N×N chessboard such that no two queens attack each other.
   - A queen can attack another queen if they share the same row, column, or diagonal.

2. Define a board[N][N], initially filled with 0s.
   - A cell with 1 means a queen is placed there.

3. Create a recursive function `solveNQUtil(col)`:
   - Input: Current column number where we are trying to place a queen.
   - Base Case: If col >= N, all queens are placed successfully; return true.
   - Try placing a queen in all rows of the current column:
       a. For each row i in column col:
           i.   Check if placing a queen at (i, col) is safe using `isSafe(i, col)`.
                - Check all previous columns for the same row.
                - Check upper left diagonal.
                - Check lower left diagonal.
           ii.  If safe:
                - Place the queen at (i, col) by setting board[i][col] = 1.
                - Recur to place the rest of the queens in the next columns (col + 1).
                - If recursion returns true, return true.
                - Else, BACKTRACK by removing the queen (set board[i][col] = 0).

4. If no row in the current column is safe, return false (trigger backtracking).

5. In `main()`:
   - Call `solveNQUtil(0)` to start placing from the first column.
   - If a solution is found, print the board using `printSolution()`.
   - Else, print that no solution exists.

6. The `isSafe(row, col)` function:
   - Ensures no queen can attack the new position (row, col) from:
       - Left row
       - Upper-left diagonal
       - Lower-left diagonal

7. This algorithm finds one valid configuration of N queens using recursion and backtracking.
*/
