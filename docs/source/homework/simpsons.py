import math


def simpsons(a, b, N, func):
    """Integrate function func(x) from a to b using N intervals of
    the Simpson's rule"""

    dx = (b - a) / N

    I = 0
    for n in range(0, N, 2):
        xl = a + dx * n
        xc = a + dx * (n+1)
        xr = a + dx * (n+2)

        fl = func(xl)
        fc = func(xc)
        fr = func(xr)

        I += dx / 3 * (fl + 4.0 * fc + fr)

    return I

# test out our Simpson's rule
a = 0.5
b = 1.5

I_exact = 1.0 - 1.0 / (2.0 * math.pi**2)

for N in [2, 4, 8, 16, 32, 64, 128]:
    I = simpsons(a, b, N,
                 lambda x: 1.0 + 0.25 * x * math.sin(math.pi * x))

    err = abs(I - I_exact)

    print(f"{N:3} {I:7.5f} {err:9.6g}")
