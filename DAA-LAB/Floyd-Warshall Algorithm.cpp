#include <stdio.h>

#define V 4
#define INF 99999

void floydWarshall(int graph[V][V]) {
    int dist[V][V];

    // Initialize distance matrix
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            dist[i][j] = graph[i][j];

    // Update distances using intermediate vertices
    for (int k = 0; k < V; k++)
        for (int i = 0; i < V; i++)
            for (int j = 0; j < V; j++)
                if (dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];

    // Print result
    printf("Shortest distances between every pair of vertices:\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (dist[i][j] == INF)
                printf("%4s", "INF");
            else
                printf("%4d", dist[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int graph[V][V] = {
        {0,   5,  INF, 10},
        {INF, 0,   3, INF},
        {INF, INF, 0,   1},
        {INF, INF, INF, 0}
    };

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
