#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

#define V 5 // Number of vertices

// Function to find the vertex with minimum distance value
int minDistance(int dist[], bool visited[]) {
    int min = INT_MAX, min_index = -1;

    for (int v = 0; v < V; v++) {
        if (!visited[v] && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }

    return min_index;
}

// Function to implement Dijkstra's algorithm
void dijkstra(int graph[V][V], int src) {
    int dist[V]; // Output array. dist[i] holds the shortest distance from src to i
    bool visited[V]; // visited[i] will be true if vertex i's shortest distance is finalized

    // Initialize all distances as INFINITE and visited[] as false
    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        visited[i] = false;
    }

    dist[src] = 0; // Distance of source vertex from itself is always 0

    // Find shortest path for all vertices
    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, visited);

        visited[u] = true;

        for (int v = 0; v < V; v++) {
            if (!visited[v] && graph[u][v] && dist[u] != INT_MAX
                && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    // Print the constructed distance array
    printf("Vertex\tDistance from Source\n");
    for (int i = 0; i < V; i++)
        printf("%d\t%d\n", i, dist[i]);
}

int main() {
    // Example graph represented as adjacency matrix
    int graph[V][V] = { {0, 10, 0, 0, 5},
                        {0, 0, 1, 0, 2},
                        {0, 0, 0, 4, 0},
                        {7, 0, 6, 0, 0},
                        {0, 3, 9, 2, 0} };

    int source = 0; // Starting node
    dijkstra(graph, source);

    return 0;
}

