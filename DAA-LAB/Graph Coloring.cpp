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

