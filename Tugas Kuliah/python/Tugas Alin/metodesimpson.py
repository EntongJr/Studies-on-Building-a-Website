# Nama : Achmad Dimas Saktiawannur Rofiq
# Kelas : Metode Numerik A - 081
# NPM : 24081010354
import numpy as np
import matplotlib.pyplot as plt

x = np.array([0, 1, 2, 3, 4])
fx = np.array([3, 9, 27, 57, 99])

h = 1

hasil = (h/3) * (fx[0] + fx[-1] + 4*(fx[1] + fx[3]) + 2*(fx[2]))
print("Hasil Integral Simpson 1/3 =", hasil)

plt.plot(x, fx, marker='o')
plt.xlabel('x')
plt.ylabel('f(x)')
plt.title('Grafik f(x)')
plt.grid(True)
plt.show()
