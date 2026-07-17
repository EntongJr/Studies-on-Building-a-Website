#include <stdio.h>


int perkalian(int a, int b){
    if (b == 0){
        return 0;  
    } else {
        return a + perkalian(a, b - 1); 
    }
}

int main(){
    int x, y;
    printf("Program Rekursif Perkalian\n");
    printf("Masukkan angka pertama : ");
    scanf("%d", &x);
    printf("Masukkan angka kedua : ");
    scanf("%d", &y);

    printf("Hasil %d x %d = %d\n", x, y, perkalian(x, y));
    return 0;
}
