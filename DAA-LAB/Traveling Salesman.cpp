#include <stdio.h>

int tsp_g[10][10] = {
   {12, 30, 33, 10, 45},
   {56, 22, 9, 15, 18},
   {29, 13, 8, 5, 12},
   {33, 28, 16, 10, 3},
   {1, 4, 30, 24, 20}
};

int visited[10], n, cost = 0;

/* Function to generate the shortest path */
void travellingsalesman(int c) {
   int k, adj_vertex = 999;
   int min = 999;
   
   visited[c] = 1;
   printf("%d ", c + 1);
   
   for(k = 0; k < n; k++) {
      if((tsp_g[c][k] != 0) && (visited[k] == 0)) {
         if(tsp_g[c][k] < min) {
            min = tsp_g[c][k];
            adj_vertex = k;
         }
      }
   }
   
   if(min != 999) {
      cost = cost + min;
   }
   
   if(adj_vertex == 999) {
      adj_vertex = 0;
      printf("%d", adj_vertex + 1);
      cost = cost + tsp_g[c][adj_vertex];
      return;
   }
   
   travellingsalesman(adj_vertex);
}

/* Main function */
int main() {
   int i;
   n = 5;
   
   for(i = 0; i < n; i++) {
      visited[i] = 0;
   }
   
   printf("Shortest Path: ");
   travellingsalesman(0);
   
   printf("\nMinimum Cost: %d\n", cost);
   
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
