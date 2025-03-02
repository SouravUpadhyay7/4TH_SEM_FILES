import os

filename = "sourav.txt"

if os.path.exists(filename):
    os.remove(filename)
    print("File deleted successfully.")
else:
    print("File does not exist.")
