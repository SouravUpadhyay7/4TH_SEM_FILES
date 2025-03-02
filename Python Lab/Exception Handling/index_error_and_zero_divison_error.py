try:
    even_numbers = [2, 4, 6]  # Corrected variable name (no spaces allowed)
    
    print(even_numbers[5])  # This will raise an IndexError

except ZeroDivisionError:  # Corrected exception name
    print("Cannot divide by 0")

except IndexError:  # Corrected exception name
    print("Index out of bound")

finally:
    print("Finish")  # Corrected "Paint" to "print"
