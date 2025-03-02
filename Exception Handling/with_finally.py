a = 5  
b = 2  # Fixed missing assignment operator for 'b'

try:
    print("Resource open")  # Indicating that resource is opened
    print(a / b)  # Performing division
except Exception as e:
    print("Cannot divide by 0:", e)  # Handling any exceptions
finally:
    print("Finish")  # Ensuring this message is always printed
