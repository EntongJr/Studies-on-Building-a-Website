#include <stdio.h>
int fpangkat (int angka, int pangkat){
    if (pangkat == 0){
        return 1;
    }
    else{
        return fpangkat (angka, pangkat -1)*angka;
    }
}
int main(){
    int angka, pangkat;
    printf("Program Menghitung Pangkat\n");
    printf("Masukkan Angka = ");
    scanf("%d", &angka);
    printf("Pangkat Berapa = ");
        scanf("%d", &pangkat);
    printf("Hasilnya Adalah = %d\n", fpangkat(angka, pangkat));
}