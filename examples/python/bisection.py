ATOL = 1.e-14
RTOL = 1.e-14
MAX_ITER = 100

# Apply bisection to find a root of f(x) in the range [xleft, xright]
# Return value is None if there was an error

def bisection(xleft, xright, f):

    fleft = f(xleft)
    fright = f(xright)

    if fleft * fright > 0:
        print("no root in interval [xleft, right]")
        return None

    if fleft == 0 or fright == 0:
        print("root is one of bounds")
        return None

    xmid = 0.5 * (xleft + xright)

    iter = 0

    while iter < MAX_ITER:
        fmid = f(xmid)

        if fleft * fmid > 0.0:
            # root is in [xmid, xright]
            xleft = xmid
            fleft = fmid
        else:
            # root is in [xleft, xmid]
            xright = xmid

        err = abs(xright - xleft)
        xmid = 0.5 * (xleft + xright)

        # check if we've converged
        if err < RTOL * abs(xmid) + ATOL:
            return xmid

        iter += 1

    # check to see if we took too many iterations
    print("too many iterations")
    return None


def f(x):
    return x**3 + x**2 - 1


def main():

    # bisection on f(x) = x^3 + x^2 - 1

    print("trying bisection on f(x) = x^3 + x^2 - 1")

    root = bisection(-5.0, 5.0, f)

    if root is not None:
        print(f"x_0 = {root}; f(x_0) = {f(root)}\n")
    else:
        print("root not found")

main()

