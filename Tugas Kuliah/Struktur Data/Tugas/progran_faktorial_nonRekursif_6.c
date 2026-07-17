#include <stdio.h>

long int faktorial(int A);

int main(){
    int r;
    long int hasil; 

    printf("MENGHITUNG NILAI FAKTORIAL TANPA REKURSIF\n");
    printf("Masukkan Nilainya = ");
    scanf("%d", &r);

    hasil = faktorial(r);
    printf("Faktorial %d = %ld\n", r, hasil);

    return 0;
}

long int faktorial(int A){
    long int hasil = 1;
    for (int i = 1; i <= A; i++){
        hasil *= i;
    }
    return hasil;
}
