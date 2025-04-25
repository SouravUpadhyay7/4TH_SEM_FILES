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

