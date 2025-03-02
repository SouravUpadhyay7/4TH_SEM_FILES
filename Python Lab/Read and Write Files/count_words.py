# Open the file in read mode
with open("sourav.txt", "r") as file:
    content = file.read()

# Count words
word_count = len(content.split())

print("Total number of words in the file:", word_count)
