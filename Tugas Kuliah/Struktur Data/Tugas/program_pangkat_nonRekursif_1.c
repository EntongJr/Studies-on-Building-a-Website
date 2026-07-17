#include <stdio.h>
int fpangkat (int angka, int pangkat){
    int i;
    int hasil = 1;
    for (i = 1; i <= pangkat; i = i + 1){
        hasil = hasil * angka;
    }
    return hasil;
}

int main(){
    int angka, pangkat;
    printf("Program Menghitung pangkat\n");
    printf("Masukkan Angka = ");
    scanf("%d", &angka);
    printf("Pangkatnya Berapa = ");
    scanf("%d", &pangkat);
    printf("Hasilnya Adalah = %d\n", fpangkat (angka, pangkat));
}