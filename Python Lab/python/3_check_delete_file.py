import os

if os.path.exists("Keya.txt"):
    os.remove("Keya.txt")
    print("File deleted successfully")
else:
    print("File does not exist.")
