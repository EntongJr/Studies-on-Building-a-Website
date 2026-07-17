#include <stdio.h>

int main(){
    // rumus : Fn = F(n-1) + F(n-2)
    // deret fibonacci : 0, 1, 1, 2, 3, 5, 8, dst.
    int n, Fn, Fn_min_1, Fn_min_2; // Deklarasi Variabel

    printf("________________________________");
    printf("\n   Program C Deret Fibonacci   ");
    printf("\n________________________________\n");

    printf("Berapa jumlah deret ? ");
    scanf("%d", &n);
    printf("Fibonacci %d deret : \n", n);

    // devinisi value dari variabel
    Fn_min_1 = 1;
    Fn_min_2 = 0;

    // perulangan sebanyak jumlah deret
    for (int i = 1; i < n; i++){
        if (i == 1){
            printf("%d", Fn_min_2);
        }
        if (i == 2){
            printf("%d", Fn_min_1);
        }
        else{
            Fn = Fn_min_1 + Fn_min_2;
            Fn_min_2 = Fn_min_1;
            Fn_min_1 = Fn;
            printf("%d", Fn);
        }
    }

    printf("\n");
    printf("_________________________________");
}