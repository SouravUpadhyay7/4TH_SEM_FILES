#include <stdio.h>
#include <limits.h>
#define V 4
#define INF INT_MAX

// Function to find the minimum cost of visiting all cities and returning to the start
int tsp(int graph[V][V], int visited[], int pos, int count, int cost, int minCost) {
    if (count == V && graph[pos][0]) {
        return (cost + graph[pos][0] < minCost) ? cost + graph[pos][0] : minCost;
    }
    
    for (int i = 0; i < V; i++) {
        if (!visited[i] && graph[pos][i]) {
            visited[i] = 1;
            minCost = tsp(graph, visited, i, count + 1, cost + graph[pos][i], minCost);
            visited[i] = 0;
        }
    }
    return minCost;
}

int main() {
    int graph[V][V] = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}
    };
    
    int visited[V] = {0};
    visited[0] = 1;
    
    int minCost = tsp(graph, visited, 0, 1, 0, INF);
    
    printf("Minimum cost of traveling salesman tour: %d\n", minCost);
    return 0;
}




/*
Algorithm: Travelling Salesman Problem (TSP) using Recursion and Backtracking

1. Start from a source city (usually city 0) and mark it as visited.

2. Use a recursive function to explore all possible paths:
   a. Base Case: If all cities have been visited (count == V) and there is a return edge to the starting city:
      - Calculate the total tour cost (current cost + cost to return to start).
      - Update the minimum cost if this tour cost is smaller.

   b. Recursive Case:
      - For every city not yet visited and directly connected to the current city:
         - Mark the city as visited.
         - Recur with updated parameters: new position, increased count, and updated cost.
         - Backtrack: unmark the city to explore other paths.

3. Repeat for all valid paths and return the minimum tour cost found.

4. In `main`, initialize visited array and call the recursive function starting from city 0.

5. Output the minimum cost of the complete tour.
*/
