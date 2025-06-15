import numpy as np

# Function to find all valid neighbors of the current state
def find_neighbours(state, landscape):
    neighbours = []
    dim = landscape.shape

    if state[0] != 0:
        neighbours.append((state[0] - 1, state[1]))  # Up
    if state[0] != dim[0] - 1:
        neighbours.append((state[0] + 1, state[1]))  # Down
    if state[1] != 0:
        neighbours.append((state[0], state[1] - 1))  # Left
    if state[1] != dim[1] - 1:
        neighbours.append((state[0], state[1] + 1))  # Right
    if state[0] != 0 and state[1] != 0:
        neighbours.append((state[0] - 1, state[1] - 1))  # Top-left
    if state[0] != 0 and state[1] != dim[1] - 1:
        neighbours.append((state[0] - 1, state[1] + 1))  # Top-right
    if state[0] != dim[0] - 1 and state[1] != 0:
        neighbours.append((state[0] + 1, state[1] - 1))  # Bottom-left
    if state[0] != dim[0] - 1 and state[1] != dim[1] - 1:
        neighbours.append((state[0] + 1, state[1] + 1))  # Bottom-right

    return neighbours

# Function to climb to a better neighbor if available
def hill_climb(curr_state, landscape):
    neighbours = find_neighbours(curr_state, landscape)
    ascended = False
    next_state = curr_state

    for neighbour in neighbours:
        if landscape[neighbour] > landscape[next_state]:
            next_state = neighbour
            ascended = True

    return ascended, next_state

# Main function
def __main__():
    # Random 10x10 matrix with values from 1 to 49
    landscape = np.random.randint(1, high=50, size=(10, 10))
    print("Landscape:\n", landscape)

    # Starting position
    start_state = (3, 6)
    current_state = start_state

    count = 1
    ascending = True

    while ascending:
        print("\nStep #", count)
        print("Current state coordinates:", current_state)
        print("Current state value:", landscape[current_state])

        count += 1
        ascending, current_state = hill_climb(current_state, landscape)

    # When no better neighbor is found
    print("\nStep #", count)
    print("Optimization objective reached.")
    print("Final state coordinates:", current_state)
    print("Final state value:", landscape[current_state])

# Run the program
__main__()
import numpy as np

# Function to find all valid neighbors of the current state
def find_neighbours(state, landscape):
    neighbours = []
    dim = landscape.shape

    if state[0] != 0:
        neighbours.append((state[0] - 1, state[1]))  # Up
    if state[0] != dim[0] - 1:
        neighbours.append((state[0] + 1, state[1]))  # Down
    if state[1] != 0:
        neighbours.append((state[0], state[1] - 1))  # Left
    if state[1] != dim[1] - 1:
        neighbours.append((state[0], state[1] + 1))  # Right
    if state[0] != 0 and state[1] != 0:
        neighbours.append((state[0] - 1, state[1] - 1))  # Top-left
    if state[0] != 0 and state[1] != dim[1] - 1:
        neighbours.append((state[0] - 1, state[1] + 1))  # Top-right
    if state[0] != dim[0] - 1 and state[1] != 0:
        neighbours.append((state[0] + 1, state[1] - 1))  # Bottom-left
    if state[0] != dim[0] - 1 and state[1] != dim[1] - 1:
        neighbours.append((state[0] + 1, state[1] + 1))  # Bottom-right

    return neighbours

# Function to climb to a better neighbor if available
def hill_climb(curr_state, landscape):
    neighbours = find_neighbours(curr_state, landscape)
    ascended = False
    next_state = curr_state

    for neighbour in neighbours:
        if landscape[neighbour] > landscape[next_state]:
            next_state = neighbour
            ascended = True

    return ascended, next_state

# Main function
def __main__():
    # Random 10x10 matrix with values from 1 to 49
    landscape = np.random.randint(1, high=50, size=(10, 10))
    print("Landscape:\n", landscape)

    # Starting position
    start_state = (3, 6)
    current_state = start_state

    count = 1
    ascending = True

    while ascending:
        print("\nStep #", count)
        print("Current state coordinates:", current_state)
        print("Current state value:", landscape[current_state])

        count += 1
        ascending, current_state = hill_climb(current_state, landscape)

    # When no better neighbor is found
    print("\nStep #", count)
    print("Optimization objective reached.")
    print("Final state coordinates:", current_state)
    print("Final state value:", landscape[current_state])

# Run the program
__main__()




# Algorithm: Hill Climbing on a 2D Landscape

# Step 1: Generate a 2D grid (landscape) with random integer values.

# Step 2: Choose a starting position (state) on the grid.

# Step 3: Repeat the following steps until no better neighbor exists:
#   a. From the current state, find all valid neighboring positions in 8 directions.
#   b. Compare the value at each neighboring position with the current state's value.
#   c. If a neighbor has a higher value, select the neighbor with the highest value.
#   d. Move to that neighbor (greedy ascent).
#   e. Record the step number and update the current state.

# Step 4: If no neighbor has a higher value than the current state:
#   a. Terminate the algorithm.
#   b. The current state is the local maximum (optimization goal reached).

# Step 5: Print the coordinates and value of the final state.

# Step 6: End
