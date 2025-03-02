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

