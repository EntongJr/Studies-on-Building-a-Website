#include <stdio.h>

int main(){
    int nilai;
    int ikut;
    
    printf("Ketik 1 jika ikut EAS : ");
    scanf("%d", & ikut);

    if (ikut == 1){
        printf("Masukkan Nilai: ");
        scanf("%d", & nilai);
        if (nilai >= 80 && nilai <= 100){
            printf("Nilai EAS Anda %d dengan nilai A", nilai);
        } else if (nilai >= 70 && nilai <= 79){
            printf("Nilai EAS Anda %d dengan nilai B", nilai);
        } else if (nilai >= 60 && nilai <= 69){
            printf("Nilai EAS Anda %d dengan nilai C", nilai);
        } else if (nilai >= 50 && nilai <= 59){
            printf("Nilai EAS Anda %d dengan nilai D", nilai);
        } else {
            printf("Nilai EAS Anda %d dengan nilai E", nilai);
        }
    } else {
        printf("Anda Tidak Mengikuti EAS, Jadi Nilai Anda E");
    }
}