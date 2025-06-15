
#8 puzzle
import copy
from heapq import heappush, heappop
n = 3
row = [ 1, 0, -1, 0 ]
col = [ 0, -1, 0, 1 ]

class priorityQueue:

  def __init__(self):
    self.heap = []

  def push(self, k):
    heappush(self.heap, k)

  def pop(self):
    return heappop(self.heap)

  def empty(self):
    if not self.heap:
      return True
    else:
      return False

class node:

  def __init__(self, parent, mat, empty_tile_pos,
        cost, level):

    self.parent = parent

    self.mat = mat

    self.empty_tile_pos = empty_tile_pos

    self.cost = cost

    self.level = level

  def __lt__(self, nxt):
    return self.cost < nxt.cost

def calculateCost(mat, final) -> int:

  count = 0
  for i in range(n):
    for j in range(n):
      if ((mat[i][j]) and
        (mat[i][j] != final[i][j])):
        count += 1

  return count

def newNode(mat, empty_tile_pos, new_empty_tile_pos,
      level, parent, final) -> node:

  new_mat = copy.deepcopy(mat)

  x1 = empty_tile_pos[0]
  y1 = empty_tile_pos[1]
  x2 = new_empty_tile_pos[0]
  y2 = new_empty_tile_pos[1]
  new_mat[x1][y1], new_mat[x2][y2] = new_mat[x2][y2], new_mat[x1][y1]

  cost = calculateCost(new_mat, final)

  new_node = node(parent, new_mat, new_empty_tile_pos,
          cost, level)
  return new_node

def printMatrix(mat):

  for i in range(n):
    for j in range(n):
      print("%d " % (mat[i][j]), end = " ")

    print()

def isSafe(x, y):

  return x >= 0 and x < n and y >= 0 and y < n

def printPath(root):

  if root == None:
    return

  printPath(root.parent)
  printMatrix(root.mat)
  print()

def solve(initial, empty_tile_pos, final):

  pq = priorityQueue()

  cost = calculateCost(initial, final)
  root = node(None, initial,
        empty_tile_pos, cost, 0)

  pq.push(root)

  while not pq.empty():

    minimum = pq.pop()


    if minimum.cost == 0:


      printPath(minimum)
      return


    for i in range(4):
      new_tile_pos = [
        minimum.empty_tile_pos[0] + row[i],
        minimum.empty_tile_pos[1] + col[i], ]

      if isSafe(new_tile_pos[0], new_tile_pos[1]):


        child = newNode(minimum.mat,
                minimum.empty_tile_pos,
                new_tile_pos,
                minimum.level + 1,
                minimum, final,)


        pq.push(child)

initial = [
      [ 1, 2, 3 ],
      [ 5, 6, 0 ],
      [ 7, 8, 4 ] ]

final = [ [ 1, 2, 3 ],
    [ 5, 8, 6 ],
    [ 0, 7, 4 ] ]

empty_tile_pos = [ 1, 2 ]

solve(initial, empty_tile_pos, final)




# Algorithm for Solving 8-Puzzle using A* Search

# Step 1: Start

# Step 2: Define the goal state (final matrix configuration)

# Step 3: Create a class 'node' to represent each puzzle state
#         - Include current matrix, level (depth), cost (heuristic), position of empty tile, and parent node

# Step 4: Define a priority queue to always pick the node with the lowest (cost + level) value

# Step 5: Define a function to calculate heuristic cost:
#         - Use misplaced tile count as the heuristic
#         - Count how many tiles are not in their goal position

# Step 6: Define a function to create a new node after a valid move of the empty tile:
#         - Copy current matrix
#         - Swap the empty tile with the target position
#         - Create a new node with updated matrix, level, cost, and empty tile position

# Step 7: Define the movement directions: up, left, down, right

# Step 8: Start with the initial puzzle configuration
#         - Create the root node
#         - Push it into the priority queue

# Step 9: While the priority queue is not empty:
#         - Pop the node with the minimum cost
#         - If its cost is zero, goal is reached; print the path and exit
#         - Otherwise, for each valid direction:
#             - Generate the new tile position
#             - If valid, create a new child node and push it into the priority queue

# Step 10: Repeat until the goal state is reached or queue is empty

# Step 11: End
