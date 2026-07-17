#include <stdio.h>

void pindah(char dari, char tujuan){
    printf("pindahkan piring dari %c ke %c\n", dari, tujuan);
}

void hanoi(int n, char dari, char bantu, char tujuan){
    int total_langkah = (1 << n) - 1;

    if (n % 2 == 0){
        char temp = tujuan;
        tujuan = bantu;
        bantu = temp;
    }

    for (int i = 1; i <= total_langkah; i++){
        if (i % 3 == 1)
            pindah(dari, tujuan);
        else if (i % 3 == 2)
            pindah(dari, bantu);
        else
            pindah(bantu, tujuan);
    }
}

int main(){
    int jum_piring;

    printf("Teknik Hanoi pada C Non-Rekursif\n");
    printf("Masukkan Jumlah Piring: ");
    scanf("%d", &jum_piring);

    hanoi(jum_piring, 'A', 'B', 'C');
    return 0;
}
