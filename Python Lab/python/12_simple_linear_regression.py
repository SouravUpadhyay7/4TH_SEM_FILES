import matplotlib.pyplot as plt
from scipy import stats

x = [5,7,8,4,2,11,9,9,4,11,12,9]
y = [86,81,88,41,6,103,81,94,18,44,85,86]

slope, intercept, r, p, std_err = stats.linregress(x, y)

def myfunc(x):
    return slope * x + intercept

model = list(map(myfunc, x))

plt.scatter(x, y)
plt.plot(x, model)
plt.show()
