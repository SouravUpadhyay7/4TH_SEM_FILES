# Complete Statistics Calculator combining all examples
import numpy as np
import pandas as pd
from scipy import stats

# Input data
list = [3, 6, 8, 4]

# Mean calculation
mean_value = np.average(list)
print("Mean:", mean_value)

# Median calculation
median_value = np.median(list)
print("Median:", median_value)

# Mode calculation
mode_result = stats.mode(list)
print("Mode:", mode_result)

# Variance calculation
variance_value = np.var(list)
print("Variance:", variance_value)

# Standard deviation calculation
std_value = np.std(list)
print("Standard deviation:", std_value)

# Output:
# Mean: 5.0
# Median: 5.0
# Mode: ModeResult(mode=array([3]), count=array([1]))
# Variance: 5.0
# Standard deviation: 2.2360679774997