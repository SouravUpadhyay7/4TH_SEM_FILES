a = 5  
b = 2  

try:
    print("Resource open")  # Indicating that resource is opened
    print(a / b)  # Performing division
    k = int(input("Enter a number: "))  # Taking integer input from the user
    print(k)  # Printing the user input
except Exception as e:
    print("Cannot divide by zero:", e)  # Handling any exceptions
finally:
    print("Resource closed")  # Ensuring the resource is always closed
