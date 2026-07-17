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
    # Input ukuran matriks pertama
    while True:
        try:
            rows_a = int(input("Masukkan jumlah baris matriks 1: "))
            cols_a = int(input("Masukkan jumlah kolom matriks 1: "))
            if rows_a <= 0 or cols_a <= 0:
                print("Jumlah baris dan kolom harus lebih dari 0.")
                continue
            break
        except ValueError:
            print("Input tidak valid, masukkan angka bulat.")

    # Input ukuran matriks kedua, kolom matriks pertama harus sama dengan baris matriks kedua
    while True:
        try:
            rows_b = int(input("Masukkan jumlah baris matriks 2: "))
            cols_b = int(input("Masukkan jumlah kolom matriks 2: "))
            if rows_b <= 0 or cols_b <= 0:
                print("Jumlah baris dan kolom harus lebih dari 0.")
                continue
            if cols_a != rows_b:
                print(f"Jumlah kolom matriks 1 ({cols_a}) harus sama dengan jumlah baris matriks 2 ({rows_b}). Coba lagi.")
                continue
            break
        except ValueError:
            print("Input tidak valid, masukkan angka bulat.")

    matriks1 = input_matrix(rows_a, cols_a, 1)
    matriks2 = input_matrix(rows_b, cols_b, 2)

    print("\nMatriks 1:")
    print(matriks1)

    print("\nMatriks 2:")
    print(matriks2)

    hasil_perkalian = np.dot(matriks1, matriks2)
    print("\nHasil perkalian matriks:")
    print(hasil_perkalian)

if __name__ == "__main__":
    main()
