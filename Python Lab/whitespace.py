import re

with open("researchgame.txt", "r") as file:
    text = file.read()

x = re.search(r"\s", text)
print("The first white space character is located at position", x.start())
