# 15 Puzzle Problem

import copy
from heapq import heappush, heappop

n = 4  # 15 puzzle (4x4 grid)
row = [1, 0, -1, 0]
col = [0, -1, 0, 1]

class priorityQueue:
    def __init__(self):
        self.heap = []

    def push(self, k):
        heappush(self.heap, k)

    def pop(self):
        return heappop(self.heap)

    def empty(self):
        return len(self.heap) == 0

class node:
    def __init__(self, parent, mat, empty_tile_pos, cost, level):
        self.parent = parent
        self.mat = mat
        self.empty_tile_pos = empty_tile_pos
        self.cost = cost
        self.level = level

    def __lt__(self, nxt):
        return (self.cost + self.level) < (nxt.cost + nxt.level)

def calculateCost(mat, final) -> int:
    count = 0
    for i in range(n):
        for j in range(n):
            if mat[i][j] and mat[i][j] != final[i][j]:
                count += 1
    return count

def newNode(mat, empty_tile_pos, new_empty_tile_pos, level, parent, final) -> node:
    new_mat = copy.deepcopy(mat)
    x1, y1 = empty_tile_pos
    x2, y2 = new_empty_tile_pos
    new_mat[x1][y1], new_mat[x2][y2] = new_mat[x2][y2], new_mat[x1][y1]
    cost = calculateCost(new_mat, final)
    return node(parent, new_mat, new_empty_tile_pos, cost, level)

def printMatrix(mat):
    for i in range(n):
        for j in range(n):
            print(f"{mat[i][j]:2}", end=" ")
        print()

def isSafe(x, y):
    return 0 <= x < n and 0 <= y < n

def printPath(root):
    if root is None:
        return
    printPath(root.parent)
    printMatrix(root.mat)
    print()

def solve(initial, empty_tile_pos, final):
    pq = priorityQueue()
    cost = calculateCost(initial, final)
    root = node(None, initial, empty_tile_pos, cost, 0)
    pq.push(root)

    while not pq.empty():
        minimum = pq.pop()

        if minimum.cost == 0:
            printPath(minimum)
            return

        for i in range(4):
            new_x = minimum.empty_tile_pos[0] + row[i]
            new_y = minimum.empty_tile_pos[1] + col[i]

            if isSafe(new_x, new_y):
                child = newNode(minimum.mat, minimum.empty_tile_pos,
                                [new_x, new_y], minimum.level + 1, minimum, final)
                pq.push(child)

# Example 15-puzzle (solvable configuration)
initial = [
    [1, 2, 3, 4],
    [5, 6, 0, 8],
    [9, 10, 7, 12],
    [13, 14, 11, 15]
]

final = [
    [1, 2, 3, 4],
    [5, 6, 7, 8],
    [9, 10, 11, 12],
    [13, 14, 15, 0]
]

empty_tile_pos = [1, 2]  # Position of 0 (empty space)
solve(initial, empty_tile_pos, final)



# Algorithm: A* Search for Solving the 15 Puzzle Problem

# Step 1: Define the initial and final puzzle configurations.
#         Represent the board as a 4x4 matrix and identify the position of the empty tile (0).

# Step 2: Create a priority queue (min-heap) to explore puzzle states.
#         Each node in the queue stores:
#           - The current state of the matrix
#           - Cost: number of misplaced tiles compared to the goal (heuristic)
#           - Level: depth of the current state from the root
#           - Total cost = heuristic + level (f(n) = h(n) + g(n))

# Step 3: Push the root node (initial state) into the priority queue.

# Step 4: While the priority queue is not empty:
#   a. Remove the node with the lowest total cost.
#   b. If the heuristic cost of this node is zero (goal reached):
#      - Print the path from the initial to goal state.
#      - Stop the algorithm.
#   c. Otherwise, for each of the 4 possible directions (up, down, left, right):
#      i. Check if moving the empty tile in that direction is within bounds.
#      ii. If valid, generate a new state by swapping the empty tile with the adjacent tile.
#      iii. Calculate the cost (heuristic) of the new state.
#      iv. Create a new node with updated state, level, and cost.
#      v. Push the new node into the priority queue.

# Step 5: Repeat until the goal state is reached or no more states are left.

# Step 6: End.
