#include <stdio.h>
#include <limits.h>

#define V 5

int minKey(int key[], int mstSet[]) {
    int min = INT_MAX, minIndex;
    for (int v = 0; v < V; v++)
        if (!mstSet[v] && key[v] < min)
            min = key[v], minIndex = v;
    return minIndex;
}

// Function to construct and print MST using Prim's Algorithm
void primMST(int graph[V][V]) {
    int parent[V];
    int key[V];
    int mstSet[V];

    for (int i = 0; i < V; i++)
        key[i] = INT_MAX, mstSet[i] = 0;

    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < V - 1; count++) {
        int u = minKey(key, mstSet);
        mstSet[u] = 1;

        for (int v = 0; v < V; v++)
            if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v])
                parent[v] = u, key[v] = graph[u][v];
    }

    printf("Edge \tWeight\n");
    for (int i = 1; i < V; i++)
        printf("%d - %d \t%d\n", parent[i], i, graph[i][parent[i]]);
}

// Main function
int main() {
    int graph[V][V] = {{0, 2, 0, 6, 0},
                       {2, 0, 3, 8, 5},
                       {0, 3, 0, 0, 7},
                       {6, 8, 0, 0, 9},
                       {0, 5, 7, 9, 0}};

    primMST(graph);
    return 0;
}




/*
Algorithm: Prim’s Minimum Spanning Tree (MST)

Goal:
- Find a Minimum Spanning Tree from a weighted undirected graph.

Steps:
1. Initialize three arrays:
   a. `key[]`: Stores the minimum weight edge connecting a vertex to the MST (initialized to INF).
   b. `parent[]`: Stores the parent of each vertex in MST.
   c. `mstSet[]`: Tracks whether a vertex is included in the MST (initialized to false).

2. Set key[0] = 0 → to start from vertex 0, and parent[0] = -1 → root has no parent.

3. Repeat V-1 times:
   a. Pick the vertex `u` not yet included in MST with the smallest key value using `minKey()`.
   b. Include vertex `u` in MST by setting mstSet[u] = true.
   c. For every vertex `v` adjacent to `u`:
      - If graph[u][v] is a valid edge and v is not yet in MST
      - AND the weight is smaller than key[v], then:
        i. Update parent[v] = u
        ii. Update key[v] = graph[u][v]

4. After all vertices are included, the MST is represented by the `parent[]` array.

5. Print the MST edges:
   → Each edge is from parent[i] to i with weight graph[i][parent[i]] for i = 1 to V-1.

Helper Function:
----------------
- `minKey(key, mstSet)`:
   → Finds the index of the minimum key value from the set of vertices not yet included in MST.

Time Complexity:
----------------
- O(V^2) for adjacency matrix implementation (since for each vertex we scan all others).

Space Complexity:
-----------------
- O(V) for arrays: key[], parent[], mstSet[]

Note:
-----
- Can be optimized to O(E log V) using Min Heap and Adjacency List (with priority queue).
*/
