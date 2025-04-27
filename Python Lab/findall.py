import re

with open("sourav.txt", "r") as fp:
    text = fp.read()

matches = re.findall(r"[\w.-]+@[\w.-]+", text)
print(matches)
