#include <stdio.h>

int main(){
    char ch, s[100], sen[100];
    printf("Masukkan Satu Huruf Depan Namamu : ");
    scanf("%c", ch);
    getchar();
    // printf("Masukkan Satu Kata : ");
    // scanf("%s", s);
    // printf("Masukkan Nama : ");
    // fgets(sen, sizeof(sen), stdin);

    printf("Huruf Depan Namamu adalah : %c\n", ch);
    // printf("%s", s);
    // printf("%s", sen);
    return 0;
}