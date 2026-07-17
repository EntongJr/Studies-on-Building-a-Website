#include <stdio.h>


int perkalian(int a, int b){
    int hasil = 0;
    for (int i = 0; i < b; i++){
        hasil += a;
    }
    return hasil;
}

int main(){
    int x, y;
    printf("Program Non Rekursif Perkalian\n");
    printf("Masukkan angka pertama : ");
    scanf("%d", &x);
    printf("Masukkan angka kedua : ");
    scanf("%d", &y);

    printf("Hasil %d x %d = %d\n", x, y, perkalian(x, y));
    return 0;
}
