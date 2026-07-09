#include <stdio.h>

int main(){
    int nilai;

    printf("Masukkan Nilai: ");
    scanf("%d", & nilai);
    printf("");
    

    if(nilai >= 80 && nilai <= 100 ){
        printf("Nilai %d Anda Dinyatakan Lulus dengan Predikat A", nilai);
    } 
    else if (nilai >= 70 && nilai <= 79){
        printf("Nilai %d Anda Mempunyai Nilai dengan Predikat B", nilai);
    }
    else if (nilai >= 60 && nilai <= 69){
        printf("Nilai %d Anda Mempunyai Nilai dengan Predikat C", nilai);
    }
    else if (nilai >= 50 && nilai <= 59){
        printf("Nilai %d Anda Mempunyai Nilai dengan Predikat D", nilai);
    }
    else if (nilai <= 50){
        printf("Nilai %d Anda Mempunyai Nilai dengan Predikat E", nilai);
    } else {
        printf("Nilai %d Anda tidak ada dalam predikat nilai ", nilai);
    }

}