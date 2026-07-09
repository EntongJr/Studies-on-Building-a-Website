#include <stdio.h>
#include <conio.h>
// Deklarasi type data
typedef int angka;
typedef float pecahan;
typedef char huruf;

// Deskripsi Program
int main(){
    angka umur;
    pecahan pecah;
    huruf h;
    huruf nama[10];
    printf("Masukkan Umur Anda : "); scanf("%d", &umur);
    printf("Umur anda adalah %d", umur);
    printf("\nMasukkan Bilangan Pecahan : "); scanf("%f", &pecah);
    printf("Bilangan Pecahan %f", pecah);
    printf("\nMasukkan Huruf : "); h=getche();
    printf("\nHuruf Anda %c", h);
    printf("\nMasukkan Nama : "); scanf("%s", &nama);
    printf("Nama Anda %s", nama);
    getch();
}