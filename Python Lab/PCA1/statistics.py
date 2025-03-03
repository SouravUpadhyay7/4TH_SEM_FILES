import pandas as pd

data = {'Numbers': [10, 20, 20, 30, 40]}
df = pd.DataFrame(data)

print("Mean:", df['Numbers'].mean())
print("Median:", df['Numbers'].median())
print("Mode:", df['Numbers'].mode()[0])  # Mode can return multiple values, taking the first one
print("Standard Deviation:", df['Numbers'].std())
print("Variance:", df['Numbers'].var())
