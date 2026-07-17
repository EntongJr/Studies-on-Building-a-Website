// Kelompok 13
// 24081010354 Achmad Dimas Saktiawannur Rofiq
// 24081010297 Ali
// 24081010301 Ahmadridloabdillah

#include <stdio.h>
#include <string.h>

#define MAX 5

char parkir[MAX][10];
int front = -1, rear = -1;

// mobil masuk
void masuk(char plat[]) {
    if (rear == MAX - 1) {
        printf("Parkiran penuh! Mobil %s tidak bisa masuk.\n", plat);
        return;
    }
    if (front == -1) front = 0;
    rear++;
    strcpy(parkir[rear], plat);
    printf("Mobil %s masuk.\n", plat);
}

// mobil keluar
void keluar() {
    if (front == -1) {
        printf("Parkiran kosong!\n");
        return;
    }
    printf("Mobil %s keluar.\n", parkir[front]);
    if (front == rear) front = rear = -1;
    else front++;
}

// tampilkan isi parkiran
void tampilkan() {
    if (front == -1) {
        printf("Parkiran kosong.\n");
        return;
    }
    printf("Isi parkiran: ");
    for (int i = front; i <= rear; i++) {
        printf("[%s] ", parkir[i]);
    }
    printf("\n");
}

int main() {
    masuk("L1SA");
    masuk("W1N");
    masuk("S413I");
    masuk("P0WER");
    masuk("D1MAS");
    masuk("S4KTI"); // parkiran penuh

    tampilkan();

    keluar();
    keluar();

    tampilkan();
    return 0;
}
