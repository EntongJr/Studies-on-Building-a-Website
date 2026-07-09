#include <stdio.h>

int main(){
    char huruf;
    printf("Masukkan Huruf dengan Huruf Kapital: ");
    scanf("%c",&huruf);
    if (huruf == 'A'){
        printf("Huruf %c adalah Huruf Vokal", huruf);
    }
    else if (huruf == 'I') {
        printf("Huruf %c adalah Huruf Vokal", huruf);
    }
    else if (huruf == 'U') {
        printf("Huruf %c adalah Huruf Vokal", huruf);
    }
    else if (huruf == 'E') {
        printf("Huruf %c adalah Huruf Vokal", huruf);
    }
    else if (huruf == 'O') {
        printf("Huruf %c adalah Huruf Vokal", huruf);
    }
    else {
        printf("Huruf %c Bukan Huruf Vokal", huruf);
    }
}