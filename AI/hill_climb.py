# Hill Climbing for TSP
# Hill Climbing for TSP
import random
import numpy as np

# Coordinates of points (example distance matrix)
coordinate = np.array([
    [0, 300, 500, 600],
    [300, 0, 200, 500],
    [500, 200, 0, 400],
    [600, 500, 400, 0]
])

def generate_matrix(coordinate):
    matrix = []
    for i in range(len(coordinate)):
        for j in range(len(coordinate)):
            p = np.linalg.norm(coordinate[i] - coordinate[j])
            matrix.append(p)
    matrix = np.reshape(matrix, (len(coordinate), len(coordinate)))
    return matrix

def generate_solution(matrix):
    points = list(range(0, len(matrix)))
    solution = []
    while points:
        random_point = random.choice(points)
        solution.append(random_point)
        points.remove(random_point)
    return solution

def path_length(matrix, solution):
    cycle_length = 0
    for i in range(len(solution)):
        cycle_length += matrix[solution[i]][solution[i - 1]]
    return cycle_length

def get_best_neighbor(matrix, solution):
    neighbors = []
    for i in range(len(solution)):
        for j in range(i + 1, len(solution)):
            neighbor = solution.copy()
            neighbor[i], neighbor[j] = neighbor[j], neighbor[i]
            neighbors.append(neighbor)

    best_neighbor = neighbors[0]
    best_path = path_length(matrix, best_neighbor)

    for neighbor in neighbors:
        current_path = path_length(matrix, neighbor)
        if current_path < best_path:
            best_path = current_path
            best_neighbor = neighbor

    return best_neighbor, best_path

def hill_climbing_tsp(coordinate):
    matrix = generate_matrix(coordinate)
    current_solution = generate_solution(matrix)
    current_path = path_length(matrix, current_solution)

    best_neighbor, best_neighbor_path = get_best_neighbor(matrix, current_solution)

    while best_neighbor_path < current_path:
        current_solution = best_neighbor
        current_path = best_neighbor_path
        best_neighbor, best_neighbor_path = get_best_neighbor(matrix, current_solution)

    return current_path, current_solution

# Running the TSP Hill Climb
final_solution = hill_climbing_tsp(coordinate)
print("\nBest path length:", final_solution[0])
print("Best path order:", final_solution[1])



# Algorithm: Hill Climbing for Travelling Salesman Problem (TSP)

# Step 1: Start

# Step 2: Represent the cities using a distance matrix or coordinate points

# Step 3: Generate an initial solution (random order of cities)

# Step 4: Calculate the path length (total distance) of the current solution

# Step 5: Generate all neighboring solutions by swapping pairs of cities in the current solution

# Step 6: For each neighbor:
#         - Calculate its path length
#         - Keep track of the neighbor with the shortest path

# Step 7: If the best neighbor has a shorter path than the current solution:
#         - Update the current solution to the best neighbor
#         - Repeat Steps 5–7

# Step 8: If no better neighbor exists, stop the algorithm (local optimum reached)

# Step 9: Output the best path and its length

# Step 10: End
