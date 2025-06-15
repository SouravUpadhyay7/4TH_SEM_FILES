#include <stdio.h>
#include <stdlib.h>

#define MAX 100  // Max number of vertices

int queue[MAX], front = -1, rear = -1;
int visited[MAX]; // To track visited nodes

void enqueue(int v) {
    if (rear == MAX - 1) return;
    if (front == -1) front = 0;
    queue[++rear] = v;
}

int dequeue() {
    if (front == -1 || front > rear) return -1;
    return queue[front++];
}

void bfs(int graph[MAX][MAX], int vertices, int start) {
    for (int i = 0; i < vertices; i++) visited[i] = 0;
    
    printf("BFS Traversal: ");
    enqueue(start);
    visited[start] = 1;

    while (front <= rear) {
        int node = dequeue();
        printf("%d ", node);

        for (int i = 0; i < vertices; i++) {
            if (graph[node][i] == 1 && !visited[i]) {
                enqueue(i);
                visited[i] = 1;
            }
        }
    }
    printf("\n");
}

int main() {
    int vertices = 5;
    int graph[MAX][MAX] = { 
        {0, 1, 1, 0, 0}, 
        {1, 0, 0, 1, 1}, 
        {1, 0, 0, 0, 1}, 
        {0, 1, 0, 0, 1}, 
        {0, 1, 1, 1, 0} 
    };

    bfs(graph, vertices, 0);
    return 0;
}



/*
Algorithm: Breadth-First Search (BFS) using Adjacency Matrix and Queue

1. Initialize a visited array of size equal to the number of vertices, and set all entries to 0.

2. Create a queue to hold nodes to be explored.

3. Start BFS from the given start node:
   a. Mark the start node as visited.
   b. Enqueue the start node.

4. While the queue is not empty:
   a. Dequeue a node from the front of the queue and print it (process it).
   b. For all vertices adjacent to this node:
      - If the vertex is connected (graph[node][i] == 1) and not yet visited:
         - Mark it as visited.
         - Enqueue it.

5. Continue the process until the queue becomes empty.

6. The order of printed nodes is the BFS traversal order.
*/
