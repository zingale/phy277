import math

def trapezoid(a, b, N, func):
    """Integrate function func(x) from a to b using N intervals of
    the trapezoid rule."""

    dx = (b - a) / N

    I = 0
    for n in range(N):
        xl = a + dx * n
        xr = a + dx * (n+1)

        fl = func(xl)
        fr = func(xr)

        I += 0.5 * dx * (fl + fr)

    return I

# test out our trapezoid rule
a = 0.5
b = 1.5

I_exact = 1.0 - 1.0 / (2.0 * math.pi**2)

for N in [2, 4, 8, 16, 32, 64, 128]:
    I = trapezoid(a, b, N,
                  lambda x: 1.0 + 0.25 * x * math.sin(math.pi * x))

    err = abs(I - I_exact)

    print(f"{N:3} {I:7.5f} {err:9.6g}")

