import math

angles_deg = [5.0, 10.0, 20.0, 40.0]

print(f"{'angle (d)':10} : {'angle (r)':10} {'sine':10} {'err':10}")

for a in angles_deg:

    angle_rad = math.radians(a)
    sine = math.sin(angle_rad)
    err = abs(sine - angle_rad)

    print(f"{a:10.2f} : {angle_rad:10.3f} {sine:10.5f} {err:10.5g}")
