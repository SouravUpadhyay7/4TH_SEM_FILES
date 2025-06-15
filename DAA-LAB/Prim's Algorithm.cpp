#include <stdio.h>
#include <limits.h>

#define V 5  // Number of vertices in the graph

// Function to find the vertex with the minimum key value
int minKey(int key[], int mstSet[]) {
    int min = INT_MAX, minIndex;
    
    for (int v = 0; v < V; v++) {
        if (mstSet[v] == 0 && key[v] < min) {
            min = key[v];
            minIndex = v;
        }
    }
    
    return minIndex;
}

// Function to implement Prim's MST algorithm
void primMST(int graph[V][V]) {
    int parent[V];  // Array to store the constructed MST
    int key[V];     // Key values used to pick the minimum weight edge
    int mstSet[V];  // To represent the set of vertices included in MST

    // Initialize all keys as INFINITE
    for (int i = 0; i < V; i++) {
        key[i] = INT_MAX;
        mstSet[i] = 0;
    }
    
    key[0] = 0;  // Start with the first vertex
    parent[0] = -1;  // First node has no parent

    // Construct the MST
    for (int count = 0; count < V - 1; count++) {
        int u = minKey(key, mstSet);  // Get the vertex with the minimum key value
        mstSet[u] = 1;  // Add it to the MST

        // Update the key value and parent of the adjacent vertices
        for (int v = 0; v < V; v++) {
            if (graph[u][v] && mstSet[v] == 0 && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    // Print the MST
    printf("Edge \tWeight\n");
    for (int i = 1; i < V; i++) {
        printf("%d - %d \t%d\n", parent[i], i, graph[i][parent[i]]);
    }
}

int main() {
    // Example graph represented by an adjacency matrix
    int graph[V][V] = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}
    };
    
    primMST(graph);  // Call the Prim's MST function
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

