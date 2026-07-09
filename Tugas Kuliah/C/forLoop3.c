#include <stdio.h>

int main() {
    int matriks[2][2] = {
        {5, 6},  
        {76, 9}   
    };
    int jumlah = 0;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            jumlah += matriks[i][j];
        }
    }
    printf("Jumlah semua elemen dalam matriks adalah: %d\n", jumlah);
    return 0;
}
