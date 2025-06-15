def astaralgo(start_node, stop_node):

    open_set = set(start_node)
    closed_set = set()

    g = {}
    parents = {}

    g[start_node] = 0
    parents[start_node] = start_node

    while len(open_set) > 0:
        n = None

        for v in open_set:
            if n == None or g[v] + heuristic(v) < g[n] + heuristic(n):
                n = v

        if n == stop_node or Graph_nodes[n] == None:
            pass
        else:
            for (m, weight) in get_neighbors(n):
                if m not in open_set and m not in closed_set:
                    open_set.add(m)
                    parents[m] = n
                    g[m] = g[n] + weight
                else:
                    if g[m] > g[n] + weight:
                        g[m] = g[n] + weight
                        parents[m] = n

                        if m in closed_set:
                            closed_set.remove(m)
                            open_set.add(m)

        if n == None:
            print("Path does not exist!")
            return None

        if n == stop_node:
            path = []

            while parents[n] != n:
                path.append(n)
                n = parents[n]

            path.append(start_node)
            path.reverse()

            print("Path found: {}".format(path))
            return path

        open_set.remove(n)
        closed_set.add(n)

    print("Path does not exist!")
    return None

def get_neighbors(v):
    if v in Graph_nodes:
        return Graph_nodes[v]
    else:
        return None

def heuristic(n):
    H_dist = {
        'A': 11,
        'B': 6,
        'C': 99,
        'D': 1,
        'E': 7,
        'G': 0,
    }
    return H_dist[n]

Graph_nodes = {
    'A': [('B', 2), ('E', 3)],
    'B': [('C', 1), ('G', 9)],
    'C': None,
    'E': [('D', 6)],
    'D': [('G', 1)],
}

astaralgo('A', 'G')



# Algorithm: A* Search Algorithm

# Step 1: Initialize two sets:
#         - open_set: contains the start node
#         - closed_set: initially empty

# Step 2: Initialize dictionaries:
#         - g: to store the cost from start_node to current node
#         - parents: to store the parent of each node for path reconstruction

# Step 3: Loop until the open_set is empty:
#   a. Find the node 'n' in open_set with the lowest value of g[n] + heuristic(n)
#   b. If 'n' is the goal node:
#      - Reconstruct the path by backtracking through parents
#      - Return the path as the solution
#   c. If 'n' has neighbors:
#      - For each neighbor 'm' of 'n':
#        i. If 'm' is not in open_set and not in closed_set:
#           - Add 'm' to open_set
#           - Set parent of 'm' to 'n'
#           - Set g[m] = g[n] + weight
#        ii. Else if a better path to 'm' is found through 'n':
#           - Update g[m] and parent[m]
#           - If 'm' is in closed_set, move it to open_set
#   d. Remove 'n' from open_set and add it to closed_set

# Step 4: If open_set becomes empty and no path is found:
#         - Report that no path exists

# Step 5: End
