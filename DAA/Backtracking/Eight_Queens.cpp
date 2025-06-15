#include <stdio.h>

#define N 8 // Chessboard size (8x8)

// Function to print the chessboard
void printBoard(int board[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            printf(board[i][j] ? " Q " : " . ");
        printf("\n");
    }
    printf("\n");
}

// Function to check if a queen can be placed at board[row][col]
int isSafe(int board[N][N], int row, int col) {
    for (int i = 0; i < row; i++) // Check column
        if (board[i][col]) return 0;
    
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) // Check upper left diagonal
        if (board[i][j]) return 0;

    for (int i = row - 1, j = col + 1; i >= 0 && j < N; i--, j++) // Check upper right diagonal
        if (board[i][j]) return 0;

    return 1;
}

// Function to solve the N-Queens problem using Backtracking
int solveNQueens(int board[N][N], int row) {
    if (row >= N) { // All queens placed successfully
        printBoard(board);
        return 1;
    }

    for (int col = 0; col < N; col++) {
        if (isSafe(board, row, col)) {
            board[row][col] = 1; // Place queen
            if (solveNQueens(board, row + 1)) // Recur to place next queen
                return 1;
            board[row][col] = 0; // Backtrack
        }
    }

    return 0; // No solution found
}

// Main function
int main() {
    int board[N][N] = {0}; // Initialize board with 0

    if (!solveNQueens(board, 0))
        printf("No solution exists!\n");

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
// Time Complexity: O(N!)
// Space Complexity: O(N^2) for the board