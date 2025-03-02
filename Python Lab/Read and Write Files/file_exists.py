import os

filename = "sourav.txt"

if os.path.exists(filename):
    print("The file exists.")
else:
    print("The file does not exist.")
