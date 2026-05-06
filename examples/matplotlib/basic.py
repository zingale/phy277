import matplotlib.pyplot as plt
import numpy as np

x = np.linspace(0, 2.0 * np.pi, 100)

fig, ax = plt.subplots()
ax.plot(x, np.sin(x))
ax.set_xlabel("x")
ax.set_ylabel("sin(x)")
fig.savefig("basic.png")
