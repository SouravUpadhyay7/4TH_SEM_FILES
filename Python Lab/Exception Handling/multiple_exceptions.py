a = 6  # Corrected variable assignment
b = 2  # Added missing assignment for 'b'

try:
    k = int(input("Enter a number: "))  # Taking integer input from the user
    print(k)  # Printing user input

    print("Resource open")  # Indicating that resource is opened
    print(a / b)  # Performing division

except ZeroDivisionError as e:  # Handling division by zero error
    print("Cannot divide by zero:", e)

except ValueError as e:  # Handling invalid input (if input is not an integer)
    print("Invalid input:", e)

except Exception as e:  # Catching any other exceptions
    print("Something went wrong:", e)

finally:
    print("Resource closed")  # Ensuring this message is always printed
