import numpy as np

def input_matrix(rows, cols):
    print(f"Masukkan elemen matriks berukuran {rows}x{cols}:")
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

    matriks = input_matrix(rows, cols)
    print("\nMatriks yang Anda masukkan:")
    print(matriks)

    # Contoh operasi: transpose matriks
    transpose = np.transpose(matriks)
    print("\nTranspose matriks:")
    print(transpose)

if __name__ == "__main__":
    main()

