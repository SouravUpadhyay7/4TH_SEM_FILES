try:
    num = int(input("Enter a number: "))
    if num % 2 == 0:
        print("Even")
    else:
        raise ValueError("Odd number detected!")
except ValueError as e:
    print("Exception:", e)
