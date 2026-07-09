#include <stdio.h>

int main(){
    int bilangan1;
    int bilangan2;
    
    printf("Masukkan Bilangan Bulat Pertama: ");
    scanf("%d", &bilangan1);
    printf("Masukkan Bilangan Bulat Kedua: ");
    scanf("%d", &bilangan2);

    if (bilangan1 > bilangan2){
        printf("Bilangan Terbesar adalah %d", bilangan1);
    }
    else if (bilangan2 > bilangan1) {
        printf("Bilangan Terbesar adalah %d", bilangan2);
    }
    else {
        printf("kedua bilangan sama");
    }
}