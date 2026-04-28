import math

values = [1.0, 2.2, 10.5, 21.3, 25.4, 6.6, 4.2]

vsum = 0.0
for e in values:
    vsum += e

vavg = vsum / len(values)

vsigma = 0.0
for e in values:
    vsigma += (e - vavg)**2

vsigma = math.sqrt(vsigma / len(values))

print(f"average = {vavg:.3f}, sigma = {vsigma:.3f}")

