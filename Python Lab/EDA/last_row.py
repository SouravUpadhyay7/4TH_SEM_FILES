import pandas as pd

# Read the dataset
df = pd.read_csv("sourav.csv")

# Display last 5 rows
print("Tail:\n", df.tail())
