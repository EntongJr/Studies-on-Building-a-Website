#include <stdio.h>

int main(){
    int n, i;
    
    printf("Berapa Jumlah Element Array Yang Kamu Ingin Buat: ");
    scanf("%d", &n);
    int array[n];
    for(i = 0; i < n; i++) {
        printf("Masukkan Element Array Ke %d : ", i + 1);
        scanf("%d", &array[i]);
    };
    printf("Data yang telah Dimasukkan : ");
    for(i = 0; i < n; i++) {
        printf("%d ", array[i]);
    };
}