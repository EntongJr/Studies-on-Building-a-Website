#include <stdio.h>

int main() {
    int tinggi;
    printf("Masukkan tinggi (bilangan ganjil): ");
    scanf("%d", &tinggi);

    // Validasi
    if (tinggi % 2 == 0 || tinggi < 1) {
        printf("Tinggi harus bilangan ganjil dan lebih dari 0.\n");
        return 1;
    }

    int tengah = tinggi / 2;

    for (int i = 0; i <= tengah; i++) {
        for (int spasi = 0; spasi < i; spasi++) {
            printf(" ");
        }
        for (int bintang = 0; bintang < tinggi - 2 * i; bintang++) {
            printf("*");
        }
        printf("\n");
    }

    for (int i = tengah - 1; i >= 0; i--) {
        for (int spasi = 0; spasi < i; spasi++) {
            printf(" ");
        }
        for (int bintang = 0; bintang < tinggi - 2 * i; bintang++) {
            printf("*");
        }
        printf("\n");
    }

    return 0;
}
