import math


def is_prime(N):

    prime = True

    max_factor = int(math.sqrt(N))

    for q in range(2, max_factor+1):
        if N % q == 0:
            prime = False
            break

    return prime

N_MAX = 100

for n in range(2, N_MAX+1):
    if is_prime(n):
        print(f"{n} is prime!")
