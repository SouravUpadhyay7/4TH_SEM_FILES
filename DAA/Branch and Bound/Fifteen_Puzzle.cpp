#include <stdio.h>
#include <stdlib.h>

#define N 4 // 4x4 Puzzle Grid

// Function to print the puzzle
void printPuzzle(int puzzle[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (puzzle[i][j] == 0)
                printf("  _ ");
            else
                printf("%3d ", puzzle[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Function to find the position of the blank tile (0)
void findBlank(int puzzle[N][N], int *x, int *y) {
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (puzzle[i][j] == 0) {
                *x = i;
                *y = j;
                return;
            }
}

// Function to swap two values
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to move the blank tile in the given direction
void moveTile(int puzzle[N][N], char move) {
    int x, y;
    findBlank(puzzle, &x, &y);

    if (move == 'w' && x > 0)      // Move Up
        swap(&puzzle[x][y], &puzzle[x - 1][y]);
    else if (move == 's' && x < N - 1) // Move Down
        swap(&puzzle[x][y], &puzzle[x + 1][y]);
    else if (move == 'a' && y > 0)  // Move Left
        swap(&puzzle[x][y], &puzzle[x][y - 1]);
    else if (move == 'd' && y < N - 1) // Move Right
        swap(&puzzle[x][y], &puzzle[x][y + 1]);
}

// Function to check if the puzzle is solved
int isSolved(int puzzle[N][N]) {
    int correct = 1;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (puzzle[i][j] != (i * N + j + 1) % (N * N))
                return 0; // Not solved yet
    return 1; // Solved!
}

// Main function
int main() {
    int puzzle[N][N] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 0, 12},
        {13, 14, 11, 15}
    };

    char move;
    printf("Welcome to the 15-Puzzle Solver!\n");
    while (!isSolved(puzzle)) {
        printPuzzle(puzzle);
        printf("Move using W (Up), A (Left), S (Down), D (Right): ");
        scanf(" %c", &move);
        moveTile(puzzle, move);
    }

    printf("Congratulations! Puzzle Solved!\n");
    printPuzzle(puzzle);

    return 0;
}



/*
Algorithm for 15-Puzzle Game using Backtracking-Like Moves

1. Start

2. Define the size of the puzzle as a 4x4 grid (N = 4).

3. Initialize a 2D array 'puzzle' with tile values from 1 to 15 and 0 as the blank tile.

4. Define a function `printPuzzle()`:
   a. Loop through all rows and columns.
   b. Print each tile value; print '_' for the blank tile (value 0).

5. Define a function `findBlank(puzzle, *x, *y)`:
   a. Search the entire puzzle to find the coordinates of the blank tile (0).
   b. Store the coordinates in variables pointed by x and y.

6. Define a utility function `swap(*a, *b)` to swap values of two tiles.

7. Define a function `moveTile(puzzle, move)`:
   a. Find the blank tile position using `findBlank`.
   b. Based on input move character ('w', 'a', 's', 'd'):
      i.   'w': if blank not in first row, swap with tile above (move up).
      ii.  's': if blank not in last row, swap with tile below (move down).
      iii. 'a': if blank not in first column, swap with tile left (move left).
      iv.  'd': if blank not in last column, swap with tile right (move right).

8. Define a function `isSolved(puzzle)`:
   a. Check whether all elements are in correct order:
      i.  Tile at position (i,j) should be (i*N + j + 1) modulo (N*N).
      ii. Last tile must be 0 (blank).
   b. If all match, return true; else return false.

9. In `main()`:
   a. Display welcome message.
   b. Loop until the puzzle is solved:
      i.   Display the current puzzle using `printPuzzle()`.
      ii.  Ask the user to input a move (w/a/s/d).
      iii. Call `moveTile()` with user move.
   c. Once solved, display congratulations and final puzzle state.

10. End
*/
