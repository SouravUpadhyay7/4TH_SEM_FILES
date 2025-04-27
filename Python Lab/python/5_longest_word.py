file = open("Keya.txt", "r")
words = file.read().split()
file.close()

longest_word = max(words, key=len)
print("Longest word:", longest_word)
