file = open("Key.txt", "w")
file.write("Python is amazing\nWelcome to Python")
file.close()

file = open("Key.txt", "r")
content = file.read()
print("File content:\n", content)
file.close()
