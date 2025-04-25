#include <stdio.h>
#include <stdlib.h>

#define V 4  // Number of vertices in the graph
#define E 5  // Number of edges in the graph

// Structure to represent an edge
struct Edge {
    int src, dest, weight;
};

// Structure to represent a subset for Union-Find
struct Subset {
    int parent;
    int rank;
};

// Function to compare two edges (for sorting)
int compareEdges(const void *a, const void *b) {
    struct Edge *edgeA = (struct Edge *)a;
    struct Edge *edgeB = (struct Edge *)b;
    return edgeA->weight > edgeB->weight;
}

// Find function of Union-Find
int find(struct Subset subsets[], int i) {
    if (subsets[i].parent != i) {
        subsets[i].parent = find(subsets, subsets[i].parent);
    }
    return subsets[i].parent;
}

// Union function of Union-Find
void unionSet(struct Subset subsets[], int x, int y) {
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);

    if (subsets[xroot].rank < subsets[yroot].rank) {
        subsets[xroot].parent = yroot;
    } else if (subsets[xroot].rank > subsets[yroot].rank) {
        subsets[yroot].parent = xroot;
    } else {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

// Kruskal's MST function
void kruskalMST(struct Edge edges[]) {
    struct Subset subsets[V];

    // Sort edges in increasing order of their weight
    qsort(edges, E, sizeof(edges[0]), compareEdges);

    // Initialize subsets
    for (int i = 0; i < V; i++) {
        subsets[i].parent = i;
        subsets[i].rank = 0;
    }

    // Loop through edges and pick the smallest edge if it doesn't form a cycle
    int mst_weight = 0;
    printf("Edge \tWeight\n");
    for (int i = 0; i < E; i++) {
        int x = find(subsets, edges[i].src);
        int y = find(subsets, edges[i].dest);

        if (x != y) {
            printf("%d - %d \t%d\n", edges[i].src, edges[i].dest, edges[i].weight);
            mst_weight += edges[i].weight;
            unionSet(subsets, x, y);
        }
    }
    printf("Weight of MST: %d\n", mst_weight);
}

int main() {
    // Example graph edges
    struct Edge edges[] = {
        {0, 1, 10},
        {0, 2, 6},
        {0, 3, 5},
        {1, 3, 15},
        {2, 3, 4}
    };

    kruskalMST(edges);  // Call the Kruskal's MST function
    return 0;
}

