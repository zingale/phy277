import numpy as np

# create our sampled data, f(x) = sin(x)
x = np.linspace(0.0, 2.0 * np.pi, 25)
f = np.sin(x)

# let's do it manually first
dfdx = np.zeros_like(f)
for i in range(1, len(f)-1):
    dfdx[i] = (f[i+1] - f[i-1]) / (x[i+1] - x[i-1])

# now construct (f[i + 1] - f[i-1]) / (x[i+1] - x[i-1])
# using views
dfdx2 = (f[2:] - f[:-2]) / (x[2:] - x[:-2])

# finally output, and compare to the exact result, cos(x)
for xc, fc, fc2 in zip(x[1:-1], dfdx[1:-1], dfdx2):
    print(f"{xc:7.4f}  {fc:7.4f}  {fc2:7.4f}  {np.cos(xc):7.4f}")
