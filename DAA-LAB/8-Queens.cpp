#include <stdio.h>
#include <stdbool.h>

#define N 8

// Function to print the chessboard
void printSolution(int board[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

// Function to check if a queen can be placed on board[row][col]
bool isSafe(int board[N][N], int row, int col) {
    // Check this row on left side
    for (int i = 0; i < col; i++) {
        if (board[row][i] == 1) {
            return false;
        }
    }

    // Check upper diagonal on left side
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 1) {
            return false;
        }
    }

    // Check lower diagonal on left side
    for (int i = row, j = col; j >= 0 && i < N; i++, j--) {
        if (board[i][j] == 1) {
            return false;
        }
    }

    return true;
}

// Function to solve the 8-Queens problem using backtracking
bool solveNQUtil(int board[N][N], int col) {
    // If all queens are placed
    if (col >= N) {
        return true;
    }

    // Consider this column and try placing this queen in all rows one by one
    for (int i = 0; i < N; i++) {
        if (isSafe(board, i, col)) {
            // Place the queen on board[i][col]
            board[i][col] = 1;

            // Recur to place the rest of the queens
            if (solveNQUtil(board, col + 1)) {
                return true;
            }

            // If placing queen in board[i][col] doesn't lead to a solution, backtrack
            board[i][col] = 0;
        }
    }

    // If the queen cannot be placed in any row in this column
    return false;
}

// Main function to solve the 8-Queens problem
void solveNQ() {
    int board[N][N] = {0};  // Initialize the board with 0s

    if (solveNQUtil(board, 0)) {
        printSolution(board);
    } else {
        printf("Solution does not exist\n");
    }
}

int main() {
    solveNQ();  // Call the function to solve the 8-Queens problem
    return 0;
}


/*
Algorithm for Solving N-Queens Problem using Backtracking

1. Start

2. Define an N x N chessboard (2D array) and initialize all cells to 0.

3. Define a function isSafe(board, row, col) to check if a queen can be placed at (row, col):
   a. Check all rows above in the current column.
   b. Check the upper left diagonal.
   c. Check the upper right diagonal.
   d. If no queen is attacking, return true.

4. Define a recursive function solveNQueens(board, row):
   a. If row >= N, then all queens are placed:
      - Print the board configuration.
      - Return true.
   b. For each column in the current row:
      i.   If placing a queen at (row, col) is safe:
           - Place the queen (board[row][col] = 1).
           - Recur to place the rest of the queens in the next row.
           - If recursive call returns true, return true.
           - Else, backtrack (board[row][col] = 0).
   c. If no valid column is found in this row, return false.

5. In main():
   a. Initialize the board with all 0s.
   b. Call solveNQueens(board, 0) to start placing from the first row.
   c. If no solution is found, print "No solution exists!".

6. End
*/

