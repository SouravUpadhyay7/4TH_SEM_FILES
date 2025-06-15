#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 4  // 4x4 grid for the 15-puzzle

// Structure for representing the puzzle state
typedef struct {
    int puzzle[N][N];  // Puzzle state
    int x, y;          // Coordinates of the empty space (0)
    int depth;         // Depth of the current state in the search tree
} PuzzleState;

// Function to print the puzzle
void printPuzzle(int puzzle[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%2d ", puzzle[i][j]);
        }
        printf("\n");
    }
}

// Check if the puzzle is in the goal state
int isGoal(int puzzle[N][N]) {
    int goal[N][N] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 0}
    };

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (puzzle[i][j] != goal[i][j]) {
                return 0;
            }
        }
    }
    return 1;
}

// Function to move the empty space in the puzzle
int isSafeMove(int x, int y) {
    return (x >= 0 && x < N && y >= 0 && y < N);
}

// Function to perform BFS to solve the 15-puzzle
void solve15Puzzle(int initialPuzzle[N][N]) {
    // Implementation of BFS or DFS to find the solution would go here
    // A full implementation would require maintaining a queue of PuzzleStates
    // and expanding each state by moving the empty space.
    // For brevity, this part is not fully implemented in this snippet.
    
    printf("15 Puzzle solving logic using BFS/DFS would go here...\n");
}

int main() {
    // Initial configuration of the 15 puzzle (example)
    int initialPuzzle[N][N] = {
        {5, 1, 3, 4},
        {2, 0, 6, 7},
        {9, 10, 8, 11},
        {13, 14, 15, 12}
    };

    printf("Initial Puzzle State:\n");
    printPuzzle(initialPuzzle);

    if (isGoal(initialPuzzle)) {
        printf("Puzzle is already solved!\n");
    } else {
        printf("Solving the 15 Puzzle...\n");
        solve15Puzzle(initialPuzzle);
    }

    return 0;
}

/*
Algorithm: 15-Puzzle Solver using BFS (Breadth-First Search)

1. Define the GOAL STATE of the 15-puzzle:
   The goal is to arrange the tiles in order:
       1  2  3  4
       5  6  7  8
       9 10 11 12
      13 14 15  0

2. Represent the puzzle state:
   - Use a 4x4 grid (2D array) to represent the current puzzle configuration.
   - Keep track of the blank space (0) using its (row, column) coordinates.

3. Create a queue (FIFO) to implement BFS.
   - Each item in the queue stores a puzzle state, blank tile position, and depth (number of moves made).
   - Optionally, store the parent state to reconstruct the path later.

4. Create a set or hash map to store visited puzzle states.
   - This helps in avoiding cycles and redundant work.

5. Enqueue the initial puzzle state and mark it as visited.

6. While the queue is not empty:
   a. Dequeue the front puzzle state from the queue.
   b. If the current puzzle matches the GOAL STATE, stop the search.
   c. For each of the 4 possible directions (UP, DOWN, LEFT, RIGHT):
       i.   Check if moving the blank tile in that direction is valid.
       ii.  If valid, create a new puzzle state by swapping 0 with the adjacent tile.
       iii. If this new state has not been visited before:
            - Mark it as visited.
            - Enqueue the new state into the queue.

7. If the queue becomes empty and the GOAL STATE was not reached, the puzzle is unsolvable.

8. Optional: Once the goal is found, backtrack from the goal state to the initial state using parent links to print the move sequence.

Note:
- BFS guarantees the shortest number of moves to reach the solution.
- This algorithm uses a brute-force level-wise search, so it may consume a lot of memory for deep states.
*/
