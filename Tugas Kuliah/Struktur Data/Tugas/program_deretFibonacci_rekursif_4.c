#include <stdio.h>

int F(int n){
    if (n == 0 || n == 1){
        return n;
    } else{
        return F(n-1) + F(n-2); //Rekrusif
    }
}

int main(){
    // rumus : Fn = F(n-1) + F(n-2)
    // deret fibonacci : 0, 1, 1, 2, 3, 5, 8, dst.

    int n;

    printf("_____________________________\n");
    printf("  Program C Deret Fibonacci  \n");
    printf("       Fungsi Rekrusif       \n");
    printf("_____________________________\n");

    printf("  Berapa Jumlah Deret ?  ");
    scanf("%d", &n);
    printf("   Fibonacci %d deret : \n", n);

    // perulangan untuk memanggil fungsi F = fibonacci sebanyak n
    for (int i = 0; i < n; i++){
        printf("%d", F(i));
    }
    printf("\n______________________________");
}