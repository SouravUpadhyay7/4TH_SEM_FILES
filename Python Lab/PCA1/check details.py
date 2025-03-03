import pandas as pd

df = pd.read_csv('data.csv')
print(df.head())  # Display first few rows
print("Missing values:\n", df.isnull().sum())  # Check for missing values
print("Unique values:\n", df.nunique())  # Check unique values in each column
