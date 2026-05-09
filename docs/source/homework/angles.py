import math

angles = []
for n in range(9):
    angles.append(math.pi * n / 8)

sines = []
for a in angles:
    sines.append(math.sin(a))

for a, s in zip(angles, sines):
    print(f"{a:7.4f}: {s:7.4f}")

