import numpy as np
import seaborn as sns
import matplotlib.pyplot as plt

sns.distplot(np.random.normal(size=1000), hist=True, kde=False)
plt.show()
