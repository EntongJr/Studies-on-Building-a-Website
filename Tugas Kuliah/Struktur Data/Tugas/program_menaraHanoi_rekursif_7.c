#include <stdio.h>

void hanoi(int n, char dari, char bantu, char tujuan){
    if(n == 1){
        printf("pindahkan piring dari %c ke %c \n", dari, tujuan);
    }else{
        hanoi(n-1, dari, tujuan, bantu);
        hanoi(1, dari, bantu, tujuan);
        hanoi(n-1, bantu, dari, tujuan);
    }
}

int main(){
    int jum_piring;

    printf("Teknik Hanoi pada C\n");
    printf("Masukkan Jumlah Piring: ");
    scanf("%d", &jum_piring);
    
    hanoi(jum_piring, 'A', 'B', 'C');
}