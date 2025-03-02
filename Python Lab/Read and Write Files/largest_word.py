# Open the file in read mode
with open("sourav.txt", "r") as file:
    content = file.read()

# Find the largest word
words = content.split()
largest_word = max(words, key=len)

print("The largest word in the file is:", largest_word)
