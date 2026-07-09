#include <stdio.h>

typedef char huruf;
typedef int angka;
typedef float pecahan;

int main(){
    huruf nama[30];
    angka umur;
    pecahan ipk;

    printf("Masukkan Nama Anda : "); 
    scanf("%s", nama);
    printf("Nama Anda : %s\n", nama);

    printf("Masukkan Umur Anda : "); 
    scanf("%d", &umur);
    printf("Umur Anda : %d\n", umur);

    printf("Masukkan Nilai Ipk Anda : "); 
    scanf("%g", &ipk);
    printf("Ipk Anda : %g\n", ipk);

    return 0;
}