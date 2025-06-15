#include <stdio.h>

#define V 5   // Number of vertices
#define E 7   // Number of edges

typedef struct {
    int src, dest, weight;
} Edge;

Edge edges[E];  // Array to store edges
int parent[V];  // Parent array for union-find

// Function to find root of a node
int find(int i) {
    while (parent[i] != i)
        i = parent[i];
    return i;
}

// Function to perform union of two sets
void unionSet(int u, int v) {
    int rootU = find(u);
    int rootV = find(v);
    parent[rootU] = rootV;
}

// Function to implement Kruskal�s Algorithm
void kruskalMST() {
    int totalWeight = 0;

    // Initialize each node as its own parent
    for (int i = 0; i < V; i++)
        parent[i] = i;

    // Sort edges by weight (Bubble Sort for simplicity)
    for (int i = 0; i < E - 1; i++) {
        for (int j = 0; j < E - i - 1; j++) {
            if (edges[j].weight > edges[j + 1].weight) {
                Edge temp = edges[j];
                edges[j] = edges[j + 1];
                edges[j + 1] = temp;
            }
        }
    }

    printf("Edges in MST:\n");
    for (int i = 0, count = 0; count < V - 1 && i < E; i++) {
        if (find(edges[i].src) != find(edges[i].dest)) {
            printf("%d - %d  (%d)\n", edges[i].src, edges[i].dest, edges[i].weight);
            totalWeight += edges[i].weight;
            unionSet(edges[i].src, edges[i].dest);
            count++;
        }
    }

    printf("Total Weight of MST: %d\n", totalWeight);
}

// Main function
int main() {
    edges[0] = (Edge){0, 1, 2};
    edges[1] = (Edge){0, 3, 6};
    edges[2] = (Edge){1, 2, 3};
    edges[3] = (Edge){1, 3, 8};
    edges[4] = (Edge){1, 4, 5};
    edges[5] = (Edge){2, 4, 7};
    edges[6] = (Edge){3, 4, 9};

    kruskalMST();
    return 0;
}

/*
Algorithm: Kruskal’s Minimum Spanning Tree (MST)

1. Initialize:
   - Each vertex is its own parent for union-find (disjoint set).

2. Sort all edges in ascending order based on their weight.

3. Initialize count = 0 and totalWeight = 0.

4. For each edge in sorted order:
   a. If including the current edge (u, v) does not form a cycle:
      - i.e., if find(u) != find(v):
         i. Add edge (u, v) to the MST.
         ii. Perform union of u and v (merge the sets).
         iii. Increment count of edges added to MST.
         iv. Add the weight of the edge to totalWeight.

   b. Stop when count == V - 1 (MST complete with V-1 edges).

5. Print all edges in the MST and the total weight.

Supporting Functions:
---------------------
- `find(i)`:
   → Uses simple path traversal to find the root of node `i`.

- `unionSet(u, v)`:
   → Finds roots of `u` and `v`, and merges them by updating parent of one root.

Time Complexity:
----------------
- Sorting edges: O(E log E)
- Union-Find operations: O(E * α(V)) with optimized union-find (not used here, simple linear find used)
- Overall: O(E log E) if optimized

Space Complexity:
-----------------
- O(V + E) for parent array and edge list
*/
