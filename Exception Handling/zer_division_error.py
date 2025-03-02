a = 45  # Assigning value 45 to variable 'a'
b = 0   # Assigning value 0 to variable 'b'

try:
    print(a / b)  # Attempting division
except ZeroDivisionError:  # Handling division by zero error
    print("Cannot divide by 0")
    
print("Finish")  # Printing "Finish" after the exception handling
