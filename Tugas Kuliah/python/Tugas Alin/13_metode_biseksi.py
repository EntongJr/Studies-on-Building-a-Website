# Kelompok 13
# 24081010354 Achmad Dimas Saktiawannur Rofiq
# 24081010355 Fiko Octaviano M
# 24081010357 Piter Rudi Irson Lapon
# 24081010358 Fitriani Navisa Wailegi
import math

# Definisi Fungsi
def f(x):
    return x * math.exp(-x) + 1

# Metode Biseksi
def biseksi(a, b, tol=0.001, N=10):
    if f(a) * f(b) > 0:
        print("Tidak Ada Akar di dalam fungsi ini")
        return None

    print("Iterasi\t a\t\t b\t\t c\t\t f(a)\t\t f(b)\t\t f(c)\t\t Error")

    for i in range(N):
        c = (a + b) / 2 
        fa = f(a)
        fb = f(b)
        fc = f(c)
        error = abs(a - b)

        print(f"{i+1}\t {a:.6f}\t {b:.6f}\t {c:.6f}\t {fa:.6f}\t {fb:.6f}\t {fc:.6f}\t {error:.6f}")

        if abs(fc) < tol or error < tol:
            print(f"\nAkar ditemukan di x = {c:.6f} setelah {i+1} iterasi (toleransi {tol})")
            return c

        if fa * fc < 0:
            b = c
        else:
            a = c

    print(f"\nHasil perkiraan akar setelah {N} iterasi adalah x = {c:.6f}")
    return c

root = biseksi(-1, 0, tol=0.001, N=10)
