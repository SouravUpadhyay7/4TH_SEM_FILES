#include <stdio.h>
#include <limits.h>

#define V 5  // Number of vertices

// Function to find the vertex with the minimum distance value
int minDistance(int dist[], int visited[]) {
    int min = INT_MAX, min_index;
    
    for (int v = 0; v < V; v++)
        if (visited[v] == 0 && dist[v] <= min)
            min = dist[v], min_index = v;
    
    return min_index;
}

// Function to implement Dijkstra's Algorithm
void dijkstra(int graph[V][V], int src) {
    int dist[V];     // Holds shortest distance from source
    int visited[V];  // Marks visited vertices

    // Initialize distances to infinity and visited[] to false
    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        visited[i] = 0;
    }

    dist[src] = 0;  // Distance to source is 0

    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, visited);
        visited[u] = 1;

        for (int v = 0; v < V; v++)
            if (!visited[v] && graph[u][v] && dist[u] != INT_MAX &&
                dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }

    // Print shortest distances
    printf("Vertex \t Distance from Source\n");
    for (int i = 0; i < V; i++)
        printf("%d \t\t %d\n", i, dist[i]);
}

int main() {
    int graph[V][V] = {
        {0, 10, 0, 30, 100},
        {10, 0, 50, 0, 0},
        {0, 50, 0, 20, 10},
        {30, 0, 20, 0, 60},
        {100, 0, 10, 60, 0}
    };

    dijkstra(graph, 0);  // Find shortest paths from vertex 0

    return 0;
}


/*
Algorithm: Dijkstra's Algorithm (for Single Source Shortest Path)

1. Start

2. Define a function `minDistance(dist[], visited[])`:
   a. Initialize `min` to INFINITY.
   b. Traverse all vertices `v`:
      i.   If `visited[v] == 0` and `dist[v]` is less than or equal to `min`:
           → update `min = dist[v]` and `min_index = v`
   c. Return `min_index` (vertex with minimum distance and not visited yet).

3. Define the function `dijkstra(graph[V][V], src)`:
   a. Create array `dist[]` to store shortest distances and initialize all values to INFINITY.
   b. Create array `visited[]` to mark visited vertices and initialize all values to 0.
   c. Set `dist[src] = 0` since the distance from source to itself is 0.

4. Repeat (V - 1) times:
   a. Pick the minimum distance vertex `u` from the unvisited vertices using `minDistance()`.
   b. Mark vertex `u` as visited.
   c. For every vertex `v` adjacent to `u`:
      i. If `v` is not visited,
         and there is an edge from `u` to `v` (`graph[u][v] != 0`),
         and total distance `dist[u] + graph[u][v] < dist[v]`:
         → update `dist[v] = dist[u] + graph[u][v]`.

5. After the loop, print all shortest distances from source to each vertex.

6. End
*/

