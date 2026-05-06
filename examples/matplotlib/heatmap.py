import numpy as np
import matplotlib.pyplot as plt

def g(x, y):
    return np.exp(-((x - 0.5)**2) / 0.1**2 - ((y - 0.5)**2) / 0.2**2)

N = 100
xmin = 0.0
xmax = 1.0
x = np.linspace(xmin, xmax, N)
y = x.copy()

xv, yv = np.meshgrid(x, y)

fig, ax = plt.subplots()

im = ax.imshow(g(xv, yv), origin="lower", extent=[xmin, xmax, xmin, xmax])
fig.colorbar(im, ax=ax)

fig.savefig("heatmap.png")
