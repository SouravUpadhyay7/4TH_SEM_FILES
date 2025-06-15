
#24/02/2025
#write a python progam using BFS

print("following is the code for BFS")

graph = {
    5 : [3, 7],
    3 : [2, 4],
    7 : [8],
    2 : [],
    4 : [8],
    8 : []
}

visited = []
queue = []

def bfs (visited, graph, node):
    visited.append(node)
    queue.append(node)

    while queue:
        m = queue.pop(0)
        print(m, end = " ")

        for neighbour in graph[m]:
            if neighbour not in visited:
                visited.append(neighbour)
                queue.append(neighbour)


print("Following is the Breadth-First Search")
bfs(visited, graph, 5)
print("\nVisited nodes:", visited)


# Algorithm to perform Breadth-First Search (BFS) on a graph

# Step 1: Start

# Step 2: Define the graph using an adjacency list (dictionary format)

# Step 3: Create an empty list called 'visited' to store visited nodes

# Step 4: Create an empty queue to help in level-order traversal

# Step 5: Define a BFS function that takes the visited list, graph, and starting node

# Step 6: Add the starting node to both 'visited' and 'queue'

# Step 7: While the queue is not empty:
    # a. Remove (pop) the front node from the queue
    # b. Process the node (e.g., print it)
    # c. For each neighbor of the current node:
        # i. If the neighbor has not been visited:
            # - Add it to 'visited'
            # - Add it to the queue

# Step 8: Call the BFS function with the starting node

# Step 9: End
