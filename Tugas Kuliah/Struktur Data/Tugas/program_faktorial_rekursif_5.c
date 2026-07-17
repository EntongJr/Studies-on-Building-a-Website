#include <stdio.h>
long int faktorial(int A);

int main(){
    int r, hasil;

    printf("MENGHITUNG NILAI FAKTORIAL DENGAN REKRUSIF\n");
    printf("Masukkan Nilainya = ");
    scanf("%d", &r);

    hasil = faktorial(r);
    printf("Faktorial %d = %d ", r, hasil);

}
long int faktorial (int A){
    if (A == 1){
        return(A);
    }else {
        return(A * faktorial(A-1));
    }
}