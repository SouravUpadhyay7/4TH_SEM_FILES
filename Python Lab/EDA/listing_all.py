import pandas as pd

# Read the dataset
df = pd.read_csv("sourav.csv")

# Get column names
print("Column Names:", df.columns.tolist())
