#include <stdio.h>
#include <limits.h>

#define V 5  // Number of vertices
#define E 8  // Number of edges

// Structure to represent an edge
struct Edge {
    int src, dest, weight;
};

// Function to implement Bellman-Ford Algorithm
void bellmanFord(struct Edge edges[], int src) {
    int dist[V];

    // Step 1: Initialize distances from source to all other vertices as INFINITY
    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX;
    dist[src] = 0;

    // Step 2: Relax all edges (V-1) times
    for (int i = 1; i <= V - 1; i++) {
        for (int j = 0; j < E; j++) {
            int u = edges[j].src;
            int v = edges[j].dest;
            int weight = edges[j].weight;
            if (dist[u] != INT_MAX && dist[u] + weight < dist[v])
                dist[v] = dist[u] + weight;
        }
    }

    // Step 3: Check for negative-weight cycles
    for (int i = 0; i < E; i++) {
        int u = edges[i].src;
        int v = edges[i].dest;
        int weight = edges[i].weight;
        if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
            printf("Graph contains negative weight cycle\n");
            return;
        }
    }

    // Print shortest distances
    printf("Vertex \t Distance from Source\n");
    for (int i = 0; i < V; i++)
        printf("%d \t\t %d\n", i, dist[i]);
}

int main() {
    struct Edge edges[E] = {
        {0, 1, -1}, {0, 2, 4},
        {1, 2, 3}, {1, 3, 2}, {1, 4, 2},
        {3, 2, 5}, {3, 1, 1}, {4, 3, -3}
    };

    bellmanFord(edges, 0);  // Find shortest paths from vertex 0

    return 0;
}


/*
Algorithm: Bellman-Ford Algorithm to Find Shortest Paths from a Single Source

1. Start

2. Define a constant V for the number of vertices in the graph.

3. Define a constant E for the number of edges.

4. Create a structure `Edge` with:
   - `src`   → source vertex of the edge
   - `dest`  → destination vertex
   - `weight`→ weight of the edge

5. Define an array `edges[E]` to store all edges of the graph.

6. Define a function `bellmanFord(edges[], src)`:
   a. Initialize a distance array `dist[V]`:
      - Set all distances to `INT_MAX` (infinity).
      - Set `dist[src] = 0` (distance to source is 0).
   
   b. Repeat the following for `V-1` times:
      - For each edge from `u` to `v` with weight `w`:
        i. If `dist[u]` is not `INT_MAX` and `dist[u] + w < dist[v]`, update:
           → `dist[v] = dist[u] + w`
      - This step ensures relaxation of all edges V-1 times.

   c. Check for negative-weight cycles:
      - For each edge from `u` to `v` with weight `w`:
        i. If `dist[u] + w < dist[v]`, then a negative-weight cycle exists.
        ii. Print warning and terminate algorithm.
   
   d. If no negative cycle, print the shortest distance to each vertex from the source.

7. In `main()`:
   a. Define and initialize the `edges[]` array with `E` edges.
   b. Call `bellmanFord(edges, 0)` to compute shortest paths from vertex 0.

8. End
*/

