# tower of hanoi
# 10 / 03 / 2025

def TowerofHanoi(n, source, destination, auxilliary):
  if n == 1:
    print("Move disk 1 from source", source,"to destination", destination)
    return

  TowerofHanoi(n-1, source, auxilliary, destination)
  print("Move disk", n , "from source", source, "to destination", destination)
  TowerofHanoi(n-1, auxilliary, destination, source)


n = 3
TowerofHanoi(n, 'A', 'B', 'C')



# Algorithm for Tower of Hanoi

# Step 1: Start

# Step 2: Define a function that takes:
#         - n: number of disks
#         - source: the source rod
#         - destination: the destination rod
#         - auxiliary: the auxiliary rod

# Step 3: If n == 1:
#         - Print the move from source to destination
#         - Return

# Step 4: Recursively call the function to move (n-1) disks from source to auxiliary using destination as auxiliary

# Step 5: Print the move of the nth disk from source to destination

# Step 6: Recursively call the function to move (n-1) disks from auxiliary to destination using source as auxiliary

# Step 7: End
