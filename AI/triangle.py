# 17/10/2025


# write a program to check sides of a triangle



print("Enter the sides of the triangle:")

a = float(input("1st side: "))
b = float(input("2nd side: "))
c = float(input("3rd side: "))

if a > 0 and b > 0 and c > 0:
  if a != b and b != c and a != c:
    print("Scalene")
  elif a == b == c:
    print("Equilateral")
  elif a == b or b == c or a == c:
    print("Iscosceles Triangle")
else:
  print("Not a triangle.")

# Algorithm to check the type of triangle based on its sides

# Step 1: Start

# Step 2: Prompt the user to enter the three sides of the triangle

# Step 3: Read the values of the three sides (a, b, c)

# Step 4: Check if all sides are greater than 0
#         → If not, print "Not a triangle" and stop

# Step 5: If all sides are valid:
#         → If all three sides are equal (a == b == c), it's an Equilateral triangle
#         → Else if any two sides are equal (a == b or b == c or a == c), it's an Isosceles triangle
#         → Else if all sides are different, it's a Scalene triangle

# Step 6: End
