try:
    print(1 / 1)
except ZeroDivisionError:
    print("Error!")
finally:
    print("This runs no matter what.")
