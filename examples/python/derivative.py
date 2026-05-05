import numpy as np

# create our sampled data, f(x) = sin(x)
x = np.linspace(0.0, 2.0 * np.pi, 25)
f = np.sin(x)

# now construct (f[i + 1] - f[i]) / (x[i+1] - x[i])
dfdx = (f[2:] - f[:-2]) / (x[2:] - x[:-2])

# finally output, and compare to the exact result, cos(x)
for xc, fc in zip(x[1:-1], dfdx):
    print(f"{xc:7.4f}  {fc:7.4f}  {np.cos(xc):7.4f}")
