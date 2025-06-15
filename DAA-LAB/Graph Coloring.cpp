#include <stdio.h>
#include <stdlib.h>

#define V 5  // Number of vertices in the graph

// Function to print the color assignment
void printSolution(int color[]) {
    printf("Color Assignment: \n");
    for (int i = 0; i < V; i++) {
        printf("Vertex %d -> Color %d\n", i, color[i]);
    }
}

// Function to check if a color can be assigned to a vertex
int isSafe(int graph[V][V], int color[], int v, int c) {
    for (int i = 0; i < V; i++) {
        if (graph[v][i] && color[i] == c) {
            return 0;  // If adjacent vertex has the same color
        }
    }
    return 1;  // Safe to assign color
}

// Greedy method to solve graph coloring problem
void greedyGraphColoring(int graph[V][V]) {
    int color[V];  // Array to store color assignments for vertices

    // Assign the first color to the first vertex
    color[0] = 0;

    // Assign colors to the remaining vertices
    for (int v = 1; v < V; v++) {
        // Consider all colors and assign the first valid color
        int c;
        for (c = 0; c < V; c++) {
            if (isSafe(graph, color, v, c)) {
                color[v] = c;
                break;
            }
        }
    }

    printSolution(color);
}

int main() {
    // Example graph represented as an adjacency matrix
    int graph[V][V] = {
        {0, 1, 1, 1, 0},
        {1, 0, 1, 0, 1},
        {1, 1, 0, 1, 0},
        {1, 0, 1, 0, 1},
        {0, 1, 0, 1, 0}
    };

    greedyGraphColoring(graph);
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
