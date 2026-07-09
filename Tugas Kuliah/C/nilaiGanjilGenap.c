#include <stdio.h>

int main(){
    int angka;

    printf("Masukkan Bilangan: ");
    scanf("%d", & angka);

    if (angka % 2 == 0){
        printf("%d Termasuk Bilangan Genap", angka);
    } else {
        printf("%d Termasuk Bilangan Ganjil", angka);
    }
}