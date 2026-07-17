import numpy as np

def input_matrix(rows, cols, matrix_num):
    print(f"Masukkan elemen matriks {matrix_num} berukuran {rows}x{cols}:")
    matrix = []
    for i in range(rows):
        while True:
            try:
                row = input(f"Baris {i+1} (pisahkan dengan spasi): ")
                row_values = list(map(float, row.strip().split()))
                if len(row_values) != cols:
                    print(f"Harap masukkan tepat {cols} elemen.")
                    continue
                matrix.append(row_values)
                break
            except ValueError:
                print("Input tidak valid, coba lagi.")
    return np.array(matrix)

def main():
    while True:
        try:
            rows = int(input("Masukkan jumlah baris matriks: "))
            cols = int(input("Masukkan jumlah kolom matriks: "))
            if rows <= 0 or cols <= 0:
                print("Jumlah baris dan kolom harus lebih dari 0.")
                continue
            break
        except ValueError:
            print("Input tidak valid, masukkan angka bulat.")

    matriks1 = input_matrix(rows, cols, 1)
    matriks2 = input_matrix(rows, cols, 2)

    print("\nMatriks 1:")
    print(matriks1)

    print("\nMatriks 2:")
    print(matriks2)

    penjumlahan = matriks1 + matriks2
    print("\nHasil penjumlahan matriks:")
    print(penjumlahan)

if __name__ == "__main__":
    main()
