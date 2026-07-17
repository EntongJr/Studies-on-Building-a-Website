#include <stdio.h>

int pembagian(int a, int b){
    int hasil = 0;
    if (b == 0) return -1; 

    while (a >= b){
        a -= b;   
        hasil++;
    }
    return hasil;
}

int main(){
    int x, y;
    printf("Program Pembagian Non-Rekursif\n");
    printf("Masukkan angka pertama : ");
    scanf("%d", &x);
    printf("Masukkan angka kedua : ");
    scanf("%d", &y);

    if (y == 0){
        printf("Tidak bisa dibagi 0\n");
    } else {
        printf("Hasil %d : %d = %d\n", x, y, pembagian(x, y));
    }
    return 0;
}
