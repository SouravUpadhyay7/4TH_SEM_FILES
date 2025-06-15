# DFS
# 10 / 03 / 2025
# DFS

graph = {
    '1' : ['2', '3', '4'],
    '2' : ['5', '6'],
    '3' : [],
    '4' : ['7', '8'],
    '5' : ['9', '10'],
    '6' : [],
    '7' : [],
    '8' : [],
    '9' : [],
    '10' : []
}

visited = set()

def dfs(visited, graph, node):
  if node not in visited:
    print(node)
    visited.add(node)
    for neighbour in graph[node]:
      dfs(visited, graph, neighbour)

print("Following is the Depth-First Search")
dfs(visited, graph, '1')



# Algorithm for Depth-First Search (DFS)

# Step 1: Start

# Step 2: Represent the graph using an adjacency list (dictionary format)

# Step 3: Create an empty set named 'visited' to keep track of visited nodes

# Step 4: Define a DFS function that takes the visited set, graph, and current node as input

# Step 5: Inside the DFS function:
#         - If the current node is not in the visited set:
#             a. Print or process the node
#             b. Add the node to the visited set
#             c. For each neighbor of the current node:
#                 - Recursively call the DFS function on the neighbor

# Step 6: Call the DFS function with the starting node

# Step 7: End
