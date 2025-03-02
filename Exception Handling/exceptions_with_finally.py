try:
    print("Resource open")  # Indicating that resource is opened
    a = 45  
    b = 2  
    print(a / b)  # Performing division
except Exception as e:
    print("Cannot divide by 0:", e)  # Handling any exceptions
finally:
    print("Resource closed")  # Ensuring the resource is always closed
