#include <stdio.h>

int pembagian(int a, int b){
    if (a < b){
        return 0; 
    } else {
        return 1 + pembagian(a - b, b);  
    }
}

int main(){
    int x, y;
    printf("Program Rekursif Pembagian\n");
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
