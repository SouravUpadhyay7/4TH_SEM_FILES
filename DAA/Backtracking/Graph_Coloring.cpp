#include <stdio.h>

#define N 4 // Number of vertices

int graph[N][N] = {
    {0, 1, 1, 1},
    {1, 0, 1, 0},
    {1, 1, 0, 1},
    {1, 0, 1, 0}
};

int colors[N]; // Stores colors of vertices

// Function to check if the current color assignment is valid
int isSafe(int v, int c) {
    for (int i = 0; i < N; i++)
        if (graph[v][i] && colors[i] == c) // If adjacent vertex has the same color
            return 0;
    return 1;
}

// Function to solve the graph coloring problem using backtracking
int solveGraphColoring(int v, int m) {
    if (v == N) { // All vertices colored successfully
        for (int i = 0; i < N; i++)
            printf("Vertex %d -> Color %d\n", i, colors[i]);
        printf("\n");
        return 1;
    }

    for (int c = 1; c <= m; c++) {
        if (isSafe(v, c)) {
            colors[v] = c; // Assign color
            if (solveGraphColoring(v + 1, m))
                return 1;
            colors[v] = 0; // Backtrack
        }
    }

    return 0; // No valid coloring found
}

// Main function
int main() {
    int m = 3; // Number of colors
    for (int i = 0; i < N; i++) colors[i] = 0; // Initialize colors

    if (!solveGraphColoring(0, m))
        printf("No solution exists!\n");

    return 0;
}



/*
Algorithm for Graph Coloring using Backtracking

1. Start

2. Define a graph as an adjacency matrix of size N x N, where N is the number of vertices.

3. Define an array 'colors' to store the color assigned to each vertex, initially set to 0 (uncolored).

4. Define a function isSafe(v, c) to check whether color 'c' can be assigned to vertex 'v':
   a. Traverse all vertices adjacent to vertex 'v'.
   b. If any adjacent vertex has the same color 'c', return false.
   c. Otherwise, return true.

5. Define a recursive function solveGraphColoring(v, m):
   a. If v == N (all vertices have been colored), print the color assignment and return true.
   b. For each color from 1 to m:
      i.   Check if assigning this color to vertex 'v' is safe using isSafe().
      ii.  If safe, assign the color to vertex 'v'.
      iii. Recur to assign colors to the remaining vertices (v + 1).
      iv.  If recursion returns true, return true.
      v.   Else, backtrack by resetting the color of vertex 'v' to 0.

6. In main():
   a. Set the number of colors 'm'.
   b. Initialize all vertex colors to 0.
   c. Call solveGraphColoring(0, m) to start coloring from the first vertex.
   d. If no valid coloring exists, print "No solution exists!"

7. End
*/
