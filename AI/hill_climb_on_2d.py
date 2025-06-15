
# Hill Climbing on a 2D landscape
import numpy as np

def find_neighbors(state, landscape):
    neighbors = []
    rows, cols = landscape.shape

    moves = [(-1,0), (1,0), (0,-1), (0,1), (-1,-1), (-1,1), (1,-1), (1,1)]  # 8 directions
    for dr, dc in moves:
        r, c = state[0] + dr, state[1] + dc
        if 0 <= r < rows and 0 <= c < cols:
            neighbors.append((r, c))
    return neighbors

def hill_climb_step(curr_state, landscape):
    neighbors = find_neighbors(curr_state, landscape)
    next_state = curr_state
    ascended = False

    for neighbor in neighbors:
        if landscape[neighbor] > landscape[next_state]:
            next_state = neighbor
            ascended = True

    return ascended, next_state

def main():
    landscape = np.random.randint(1, 50, size=(10, 10))  # Random 10x10 grid
    print("\nLandscape:\n", landscape)

    start_state = (3, 6)
    current_state = start_state
    step = 1

    ascending = True
    while ascending:
        print(f"\nStep #{step}")
        print(f"Current state: {current_state}")
        print(f"Value at current state: {landscape[current_state]}")
        ascending, current_state = hill_climb_step(current_state, landscape)
        step += 1

    print(f"\nOptimization reached at step #{step}")
    print(f"Final state: {current_state}")
    print(f"Final value: {landscape[current_state]}")

if __name__ == "__main__":
    main()




# Algorithm: Hill Climbing on a 2D Landscape

# Step 1: Start

# Step 2: Generate a random 2D grid (landscape) of integer values

# Step 3: Choose a random or fixed starting position (state) on the grid

# Step 4: Repeat the following until no better neighbor exists:
#         a. From the current state, find all valid neighboring positions (8 directions)
#         b. For each neighbor:
#            - Compare its value to the current state's value
#            - If a neighbor has a higher value, consider it a candidate for the next move
#         c. Select the neighbor with the highest value (greedy move)
#         d. Move to that neighbor and continue the process

# Step 5: If none of the neighbors have a higher value than the current state:
#         - Stop the search (local maximum reached)

# Step 6: Output the final state and its value

# Step 7: End
