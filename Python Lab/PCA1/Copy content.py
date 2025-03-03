with open('source.txt', 'r') as source, open('destination.txt', 'w') as dest:
    dest.write(source.read())
