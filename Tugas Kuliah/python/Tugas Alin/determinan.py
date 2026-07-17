import numpy as np

def input_matrix(size):
    print(f"Masukkan elemen matriks berukuran {size}x{size}:")
    matrix = []
    for i in range(size):
        while True:
            try:
                row = input(f"Baris {i+1} (pisahkan dengan spasi): ")
                row_values = list(map(float, row.strip().split()))
                if len(row_values) != size:
                    print(f"Harap masukkan tepat {size} elemen.")
                    continue
                matrix.append(row_values)
                break
            except ValueError:
                print("Input tidak valid, coba lagi.")
    return np.array(matrix)

def main():
    while True:
        try:
            size = int(input("Masukkan ukuran matriks (n x n): "))
            if size <= 0:
                print("Ukuran matriks harus lebih dari 0.")
                continue
            break
        except ValueError:
            print("Input tidak valid, masukkan angka bulat.")

    matriks = input_matrix(size)

    print("\nMatriks yang Anda masukkan:")
    print(matriks)

    determinan = np.linalg.det(matriks)
    print("\nDeterminan matriks:")
    print(determinan)

if __name__ == "__main__":
    main()
