#include <stdio.h>

int main(){
    int tahun;
    printf("Masukkan Tahun: ");
    scanf("%d", & tahun);
    if (tahun % 400 == 0 ){
        printf("%d adalah tahun kabisat", tahun);
    }
    else if (tahun % 100 == 0){
        printf("%d adalah tahun kabisat", tahun);
    }
    else if (tahun % 4 == 0){
        printf("%d adalah tahun kabisat", tahun);
    }
    else {
        printf("%d bukan tahun kabisat", tahun);
    }
}
