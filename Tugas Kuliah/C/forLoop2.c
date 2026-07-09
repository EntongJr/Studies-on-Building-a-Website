#include <stdio.h>

int main(){
    int n, i;
    printf("Berapa Jumlah Element Array Yang Kamu Ingin Buat: ");
    scanf("%d", &n);

    int array[n];
    int tambahan;
    float total = 0.0;

    for(i = 0; i < n; i++) {
        printf("Masukkan Element Array Ke %d : ", i + 1);
        scanf("%d", &array[i]);
    };
    for(i = 0; i < n; i++) {
        printf("Masukkan Nilai tabahan Untuk Array Ke %d :", i + 1);
        scanf("%d", &tambahan);
        array[i] += tambahan;
        total += array[i];
    }
    float rataRata = total / n;
    printf("Jadi Rata Ratanya Adalah : %f", rataRata);
}