#include <stdio.h>

int prima(int angka) {
    if (angka <= 1) {
        return 0; // Bilangan kurang dari atau sama dengan 1 bukan bilangan prima
    }
    for (int i = 2; i * i <= angka; i++) {
        if (angka % i == 0) {
            return 0; // Bilangan dapat dibagi oleh i, jadi bukan bilangan prima
        }
    }
    return 1; // Bilangan adalah bilangan prima
}

int main() {
    int angka;

    printf("Masukkan bilangan: ");
    scanf("%d", &angka);

    if (prima(angka)) {
        printf("%d adalah bilangan prima.\n", angka);
    } else {
        printf("%d bukan bilangan prima.\n", angka);
    }

    return 0;
}