import numpy as np
import matplotlib as mpl
import matplotlib.pyplot as plt
from matplotlib.patches import Polygon

mpl.rcParams['mathtext.fontset'] = 'cm'
mpl.rcParams['mathtext.rm'] = 'serif'


def f(x):
    """ the function we are integrating """
    return 1.0 + x*0.25*np.sin(np.pi*x)
    #return (1.0 + x*0.25*np.sin(5*np.pi*x)) * np.exp(-(x - 1.0)**2/0.5)


plt.rcParams.update({'xtick.labelsize': 18,
                     'ytick.labelsize': 18,
                     'font.size': 18})



def plot_base(xp, fp, xfine, a, b, label_mid=False):

    fmax = fp.max()

    for xl in xp:
        plt.plot([xl,xl], [0.0, 1.2*fmax], ls="--", color="0.5", zorder=-1)

    plt.scatter(xp, fp, marker="o", color="r", zorder=100)

    plt.figtext(0.9, 0.05, '$x$', fontsize=20)
    plt.figtext(0.1, 0.9, '$y$', fontsize=20)

    ax = plt.gca()

    ax.spines['right'].set_visible(False)
    ax.spines['top'].set_visible(False)
    ax.xaxis.set_ticks_position('bottom')

    ax.set_xticks((a, (a+b)/2, b))
    ax.set_xticklabels(('$x_0$', '$x_1$', '$x_2$'))

    ax.set_yticks([])

    plt.plot(xfine, f(xfine), "r", linewidth=2)

    plt.xlim(np.min(xfine), 1.05*np.max(xfine))
    plt.ylim(ymin=0)


def trapezoid(xp, fp, a, b):

    ax = plt.gca()

    integral = 0.0

    for n in range(len(xp)-1):

        xl = xp[n]
        xr = xp[n+1]

        # shade region
        fl = f(xl)
        fr = f(xr)

        verts = [(xl, 0), (xl, fl), (xr, fr), (xr, 0)]
        ax.add_patch(Polygon(verts, facecolor="0.8", edgecolor="k"))

        integral += 0.5 * (xr - xl) * (fl + fr)

    return integral


def main():

    N_fine = 200

    # the number of bins to divide [a, b]
    N_bins = 2

    xmin = 0.5
    xmax = 1.5

    dx_extra  = 0.5

    # add a bin on each end of the domain outside of the integral
    xmin_plot = xmin - dx_extra
    xmax_plot = xmax + dx_extra

    xfine = np.linspace(xmin_plot, xmax_plot, N_fine+2)

    xp = np.linspace(xmin, xmax, N_bins+1)

    # integral range
    a = xmin
    b = xmax

    # function points
    fp = f(xp)

    # trapezoid method

    plot_base(xp, fp, xfine, a, b)
    I_t = trapezoid(xp, fp, a, b)

    plt.savefig(f"trapezoid_N{N_bins}.png", bbox_inches="tight")

if __name__ == "__main__":
    main()



