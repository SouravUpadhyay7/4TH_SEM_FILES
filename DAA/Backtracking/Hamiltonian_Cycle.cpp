#include <stdio.h>

#define N 5 // Number of vertices

int graph[N][N] = {
    {0, 1, 0, 1, 0},
    {1, 0, 1, 1, 1},
    {0, 1, 0, 0, 1},
    {1, 1, 0, 0, 1},
    {0, 1, 1, 1, 0}
};

int path[N]; // Stores Hamiltonian Path

// Function to check if adding vertex v to the path is valid
int isSafe(int v, int pos) {
    if (!graph[path[pos - 1]][v]) return 0; // If not adjacent
    for (int i = 0; i < pos; i++) // If already in path
        if (path[i] == v) return 0;
    return 1;
}

// Function to solve Hamiltonian Cycle using backtracking
int solveHamiltonian(int pos) {
    if (pos == N) { // All vertices included
        if (graph[path[pos - 1]][path[0]]) { // Check if cycle exists
            for (int i = 0; i < N; i++)
                printf("%d -> ", path[i]);
            printf("%d\n", path[0]); // Completing the cycle
            return 1;
        }
        return 0;
    }

    for (int v = 1; v < N; v++) {
        if (isSafe(v, pos)) {
            path[pos] = v;
            if (solveHamiltonian(pos + 1))
                return 1;
            path[pos] = -1; // Backtrack
        }
    }

    return 0;
}

// Main function
int main() {
    for (int i = 0; i < N; i++) path[i] = -1; // Initialize path
    path[0] = 0; // Start from vertex 0

    if (!solveHamiltonian(1))
        printf("No Hamiltonian Cycle exists!\n");

    return 0;
}



/*
Algorithm for Hamiltonian Cycle using Backtracking

1. Start

2. Represent the graph using an adjacency matrix of size N x N.

3. Define an array 'path' to store the Hamiltonian path, initialized with -1 for all positions.

4. Set path[0] = 0 to start from the first vertex.

5. Define a function isSafe(v, pos) to check if vertex 'v' can be added at position 'pos':
   a. Check if vertex 'v' is adjacent to the previous vertex in the path (graph[path[pos - 1]][v] == 1).
   b. Check if vertex 'v' is already included in the path.
   c. If both conditions are satisfied, return true; else return false.

6. Define a recursive function solveHamiltonian(pos):
   a. If pos == N (all vertices included in path):
      i.   Check if there is an edge from the last vertex in the path back to the first to form a cycle.
      ii.  If yes, print the Hamiltonian cycle and return true.
      iii. If no edge exists back to the start, return false.
   b. For each vertex v from 1 to N-1:
      i.   If isSafe(v, pos) returns true:
           - Add vertex 'v' to path[pos].
           - Recur to fill the next position: solveHamiltonian(pos + 1).
           - If it returns true, return true.
           - Otherwise, backtrack by setting path[pos] = -1.
   c. If no vertex can be added, return false.

7. In main():
   a. Initialize all elements in path[] to -1.
   b. Set the first position in path[] to 0 (starting vertex).
   c. Call solveHamiltonian(1) to begin the process.
   d. If it returns false, print "No Hamiltonian Cycle exists!".

8. End
*/
