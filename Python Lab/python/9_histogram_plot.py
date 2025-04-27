import seaborn as sns
import matplotlib.pyplot as plt

tips = sns.load_dataset("tips")
sns.histplot(data=tips, x="size", stat="probability", discrete=True, kde=True)
plt.title("Histogram of Party Size (Tip Data)")
plt.xlabel("Size of the group")
plt.ylabel("Probability")
plt.show()
