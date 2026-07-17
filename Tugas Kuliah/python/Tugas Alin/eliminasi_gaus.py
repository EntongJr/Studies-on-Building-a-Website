# Kelompok 13
# 24081010354 Achmad Dimas Saktiawannur Rofiq
# 24081010355 Fiko Octaviano M
# 24081010357 Piter Rudi Irson Lapon
# 24081010358 Fitriani Navisa Wailegi
# Program Metode Eliminasi Gauss

import numpy as np

def gauss_elimination(a, b):
    n = len(b)
    # Membentuk matriks augmented
    aug = np.hstack([a, b.reshape(-1, 1)])

    # Proses eliminasi
    for i in range(n):
        # Pivoting: jika elemen diagonal nol, tukar baris
        if aug[i][i] == 0:
            for j in range(i+1, n):
                if aug[j][i] != 0:
                    aug[[i, j]] = aug[[j, i]]
                    break

        # Normalisasi baris pivot
        aug[i] = aug[i] / aug[i][i]

        # Eliminasi variabel dari baris di bawahnya
        for j in range(i+1, n):
            aug[j] = aug[j] - aug[i] * aug[j][i]

    # Substitusi mundur
    x = np.zeros(n)
    for i in range(n-1, -1, -1):
        x[i] = aug[i][-1] - np.sum(aug[i][i+1:n] * x[i+1:n])

    return x


# Contoh penggunaan
a = np.array(
    [[1.0, -2.0, 1.0], 
    [3.0, 1.0, -2.0], 
    [7.0, -6.0, -1.0]])
b = np.array([6.0, 4.0, 10.0])

x = gauss_elimination(a, b)
print("Hasil solusi (x, y, z):", x)