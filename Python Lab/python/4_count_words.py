file = open("Keya.txt", "r")
content = file.read()
file.close()

word_count = len(content.split())
print("Word count:", word_count)
