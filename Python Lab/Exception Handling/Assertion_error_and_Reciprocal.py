try:
    num = int(input("Enter a number: "))  # Taking user input

    assert num % 2 == 0  # Checking if the number is even
    print(num, "is even")  # Printing confirmation if assertion passes

except AssertionError:  # Handling assertion failure (if the number is not even)
    print("Not an even number.")

try:
    reciprocal = 1 / num  # Calculating reciprocal
    print("Reciprocal:", reciprocal)

except ZeroDivisionError:  # Handling division by zero
    print("Cannot calculate reciprocal of zero.")

finally:
    print("Finish")  # Ensuring this message is always printed
