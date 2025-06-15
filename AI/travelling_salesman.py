
# Travelling Salesman
# 07 - 04 - 2025


import numpy as np

def travellingsalesman(c, visited, tsp_g, n, Cost):
    adj_vertex = 999
    min_val = 999
    visited[c] = 1
    print((c + 1), end=" ")
    for k in range(n):
        if tsp_g[c][k] != 0 and visited[k] == 0:
            if tsp_g[c][k] < min_val:
                min_val = tsp_g[c][k]
                adj_vertex = k
    if min_val != 999:
        Cost += min_val


    if adj_vertex == 999:
        adj_vertex = 0
        print((adj_vertex + 1), end=" ")
        Cost += tsp_g[c][adj_vertex]
        return Cost


    return travellingsalesman(adj_vertex, visited, tsp_g, n, Cost)


n = 8
Cost = 0
visited = np.zeros(n, dtype=int)
tsp_g = np.array([[0, 5, 0, 6, 0, 4, 0, 7],
                  [5, 0, 2, 4, 3, 0, 0, 0],
                  [0, 2, 0, 1, 0, 0, 0, 0],
                  [6, 4, 1 ,0 ,7 ,0 ,0, 0],
                  [0, 3, 0, 7, 0, 0, 6, 4],
                  [4, 0, 0, 0, 0, 0, 3, 0],
                  [0, 0, 0, 0, 6, 3, 0, 2],
                  [7, 0, 0, 0, 4, 0, 2, 0]
                  ])

print("Shortest Path: ", end=" ")
Cost = travellingsalesman(0, visited, tsp_g, n, Cost)
print()
print("Minimum Cost: ", end=" ")
print(Cost)




# Algorithm for Travelling Salesman Problem (Greedy Approach)

# Step 1: Start

# Step 2: Initialize the number of cities (n), cost variable (Cost = 0), and a visited array to track visited cities

# Step 3: Create the cost matrix (graph) representing the distance between cities

# Step 4: Define a recursive function to perform the TSP:
#         - Mark the current city as visited
#         - Print the current city as part of the path
#         - Find the nearest unvisited city with the smallest non-zero cost
#         - Add the cost to the total cost
#         - If no unvisited city remains, return to the starting city and add that cost
#         - Else, call the function recursively with the next nearest city

# Step 5: Call the recursive function starting from the first city

# Step 6: Print the final path and the total minimum cost

# Step 7: End
