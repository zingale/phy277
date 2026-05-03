import vector

u = vector.Vector(3, 5)
v = vector.Vector(1, 2)

print("u = {u}")
print("v = {u}")
print()

# addition and subtraction
print(f"{u} + {v} = {u + v}")
print(f"{u} - {v} = {u - v}")
print()

# multiplication and division
print(f"2 * {u} = {2 * u}")
print(f"{u} * 2 = {u * 2}")
print(f"{u} / 3 = {u / 3}")

# abs, dot, and cross
print(f"abs(u) = {abs(u)}")
print(f"u . v = {u @ v}")
print(f"u x v = {u.cross(v)}")
