import sys

# initialize a list with 2 elements

fib = [0, 1]

N = int(input("How many terms of the Fibonacci sequence to compute? (N > 2) "))

if N <= 2:
    # we've already got 2
    sys.exit("Error: must enter N > 2")

# add to the sequence
while len(fib) < N:
    fib.append(fib[-1] + fib[-2])

# now output -- we can just print the list
print(fib)

