#include <stdio.h>

int main(){
    float x, y;
    printf("Masukkan Kordinat Titik (x, y)\n");
    printf("Masukkan X: ");
    scanf("%f", &x);
    printf("Masukkan Y: ");
    scanf("%f", &y);

    if (x > 0 && y > 0) {
        printf("Titik (%.2f, %.2f) Berada di Quadran I", x, y);
    }
    else if (x < 0 && y > 0) {
        printf("Titik (%.2f, %.2f) Berada di Quardran II", x,y);
    }
    else if (x < 0 && y < 0) {
        printf("Titik (%.2f, %.2f) Berada di Quardran III", x,y);
    }
    else if (x > 0 && y < 0) {
        printf("Titik (%.2f, %.2f) Berada di Quardran IV", x,y);
    }
    else if (x == 0 && y == 0) {
        printf("Titik (%.2f, %.2f) Berada di titik  (0, 0) ");
    }
}