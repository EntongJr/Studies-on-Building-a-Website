import math

# Fungsi f(x)
def f(x):
    return math.exp(-2 * math.sin(2 * x))

# Fungsi turunan eksak (sesuai rumus barumu)
def f_prime_exact(x):
    return -math.exp(-x) + 2 * math.cos(2 * x)

h = 0.05
x_values = [round(i * h, 10) for i in range(int(1 / h) + 1)]

print(f"{'x':<8}{'f(x)':<20}{'f\'(x) approx':<20}{'f\'(x) exact':<20}{'error':<20}")

for x in x_values:
    fx = f(x)
    fxh = f(x + h)
    approx = (fxh - fx) / h
    exact = f_prime_exact(x)
    error = abs(approx - exact)

    print(f"{x:<8.2f}{fx:<20.10f}{approx:<20.10f}{exact:<20.10f}{error:<20.10f}")
