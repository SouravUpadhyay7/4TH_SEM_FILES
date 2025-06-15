#include <stdio.h>
#define INF 99999
#define V 4

// Floyd-Warshall algorithm to find shortest paths between all pairs of vertices
void floydWarshall(int graph[V][V]) {
    int dist[V][V];
    
    // Initialize the solution matrix same as input graph matrix
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            dist[i][j] = graph[i][j];
    
    // Update distances considering each vertex as an intermediate vertex
    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }
    
    // Print the final shortest distance matrix
    printf("Shortest distances between every pair of vertices:\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (dist[i][j] == INF)
                printf("INF ");
            else
                printf("%d ", dist[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int graph[V][V] = {{0, 3, INF, 5},
                        {2, 0, INF, 4},
                        {INF, 1, 0, INF},
                        {INF, INF, 2, 0}};
    
    floydWarshall(graph);
    return 0;
}

/*
Algorithm: Floyd-Warshall Algorithm (for All Pairs Shortest Path)

1. Start

2. Input: A weighted directed graph represented as an adjacency matrix `graph[V][V]`
   - If there is no edge between vertex i and j, set `graph[i][j] = INF` (a large number like 99999).
   - Distance from a vertex to itself is 0.

3. Create a matrix `dist[V][V]` and initialize it as:
   - dist[i][j] = graph[i][j] for all i and j.

4. Use each vertex `k` as an intermediate vertex in the path:
   For k = 0 to V-1:
      For i = 0 to V-1:
         For j = 0 to V-1:
            If dist[i][k] + dist[k][j] < dist[i][j]:
               → Update dist[i][j] = dist[i][k] + dist[k][j]

5. After all iterations, the matrix `dist[i][j]` will contain the shortest distances between all pairs of vertices.

6. Print the distance matrix:
   - If dist[i][j] == INF → print "INF"
   - Else print dist[i][j]

7. End
*/
