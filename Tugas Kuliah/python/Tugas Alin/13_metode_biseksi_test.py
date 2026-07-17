# Program Metode Biseksi
# Fungsi: mencari akar dari persamaan f(x) = x^3 - x - 2

def f(x):
    return x**3 - x - 2  # Ganti dengan fungsi lain jika ingin

def biseksi(a, b, tol):
    if f(a) * f(b) >= 0:
        print("Error: f(a) dan f(b) harus memiliki tanda yang berbeda.")
        return None
    
    iterasi = 0
    print("Iterasi |   a   |   b   |   c   |  f(c)  ")
    print("------------------------------------------")
    
    while (b - a) / 2.0 > tol:
        c = (a + b) / 2.0
        iterasi += 1
        print(f"{iterasi:^8}|{a:^7.4f}|{b:^7.4f}|{c:^7.4f}|{f(c):^8.4f}")
        
        if f(c) == 0:
            # c adalah akar tepat
            return c
        elif f(a) * f(c) < 0:
            b = c
        else:
            a = c
    
    return (a + b) / 2.0

# Input awal
a = 1
b = 2
toleransi = 0.001

akar = biseksi(a, b, toleransi)

if akar is not None:
    print("\nAkar hampiran ditemukan di x =", round(akar, 6))