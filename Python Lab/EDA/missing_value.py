import pandas as pd

# Read the dataset
df = pd.read_csv("sourav.csv")

# Check for missing values
print("Missing Values:\n", df.isnull())
