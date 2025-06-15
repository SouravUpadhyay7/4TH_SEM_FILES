#include <stdio.h>

int graph[10][10] = {
   {0, 1, 1, 0, 0},
   {1, 0, 1, 1, 0},
   {1, 1, 0, 0, 1},
   {0, 1, 0, 0, 1},
   {0, 0, 1, 1, 0}
};

int visited[10];
int n = 5;

/* Function to perform DFS traversal */
void dfs(int vertex) {
   int i;
   visited[vertex] = 1;
   printf("%d ", vertex + 1);

   for(i = 0; i < n; i++) {
      if(graph[vertex][i] == 1 && visited[i] == 0) {
         dfs(i);
      }
   }
}

/* Main function */
int main() {
   int i;
   
   for(i = 0; i < n; i++) {
      visited[i] = 0;
   }
   
   printf("DFS Traversal starting from vertex 1: ");
   dfs(0);
   
   printf("\n");
   
   return 0;
}



/*
Algorithm: Depth-First Search (DFS) using Adjacency Matrix (Recursive)

1. Initialize a visited array of size equal to the number of vertices and set all entries to 0.

2. Define a recursive DFS function:
   a. If the current node is already visited, return (base case).
   b. Print the current node (i.e., process it).
   c. Mark the current node as visited.

3. For all vertices in the graph:
   a. If the current node is connected to vertex `i` (graph[node][i] == 1)
      and vertex `i` has not been visited:
      - Recursively call DFS on vertex `i`.

4. In the main function:
   a. Define and initialize the adjacency matrix representing the graph.
   b. Initialize all entries in the visited array to 0.
   c. Call the DFS function with the starting node.

5. The order of printed nodes is the DFS traversal order.
*/
