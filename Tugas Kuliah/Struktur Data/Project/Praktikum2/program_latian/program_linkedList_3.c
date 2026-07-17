// Kelompok 13
// 24081010354 Achmad Dimas Saktiawannur Rofiq
// 24081010297 Ali
// 24081010301 Ahmadridloabdillah

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Mahasiswa {
    char npm[15];
    char nama[50];
    struct Mahasiswa *next;
};

struct Mahasiswa *head = NULL; 

void tambahMahasiswa(char npm[], char nama[]) {
    struct Mahasiswa *baru, *bantu;
    baru = (struct Mahasiswa*) malloc(sizeof(struct Mahasiswa));
    strcpy(baru->npm, npm);
    strcpy(baru->nama, nama);
    baru->next = NULL;

    if (head == NULL) {
        head = baru;
    } else {
        bantu = head;
        while (bantu->next != NULL) {
            bantu = bantu->next;
        }
        bantu->next = baru;
    }
}

void prependMahasiswa(char npm[], char nama[]) {
    struct Mahasiswa *baru;
    baru = (struct Mahasiswa*) malloc(sizeof(struct Mahasiswa));
    strcpy(baru->npm, npm);
    strcpy(baru->nama, nama);
    baru->next = head;
    head = baru;

    printf("\nData %s (%s) berhasil ditambahkan di depan.\n", nama, npm);
}

void hapusDepan() {
    struct Mahasiswa *hapus;
    if (head == NULL) {
        printf("\nList kosong, tidak ada data yang bisa dihapus.\n");
        return;
    }

    hapus = head;          
    head = head->next;     
    printf("\nData di depan (%s - %s) berhasil dihapus.\n", hapus->npm, hapus->nama);
    free(hapus);           
}

void tampilMahasiswa() {
    struct Mahasiswa *bantu = head;
    if (bantu == NULL) {
        printf("\nList kosong.\n");
        return;
    }
    printf("\nData Mahasiswa:\n\n");
    while (bantu != NULL) {
        printf("NPM  : %s\n", bantu->npm);
        printf("Nama : %s\n", bantu->nama);
        printf("\n");
        bantu = bantu->next;
    }
}

void hapusMahasiswa(char npm[]) {
    struct Mahasiswa *hapus, *bantu;
    if (head == NULL) {
        printf("\nList kosong, tidak ada data\n");
        return;
    }

    if (strcmp(head->npm, npm) == 0) {
        hapus = head;
        head = head->next;
        free(hapus);
        printf("\nData dengan NPM %s berhasil dihapus.\n", npm);
        return;
    }

    bantu = head;
    while (bantu->next != NULL && strcmp(bantu->next->npm, npm) != 0) {
        bantu = bantu->next;
    }

    if (bantu->next == NULL) {
        printf("\nData dengan NPM %s tidak ditemukan.\n", npm);
    } else {
        hapus = bantu->next;
        bantu->next = hapus->next;
        free(hapus);
        printf("\nData dengan NPM %s berhasil dihapus.\n", npm);
    }
}

int main() {
    tambahMahasiswa("240101001", "Dimas Sakti");
    tambahMahasiswa("240101002", "Ali");
    tambahMahasiswa("240101003", "Ridho Abdillah");

    printf("\nData Awal");
    tampilMahasiswa();
    printf("---------------------");
    prependMahasiswa("240101000", "Budi Setiawan");
    printf("\nSetelah ditambahkan di Depan");
    tampilMahasiswa();
    printf("---------------------");
    hapusMahasiswa("240101002");
    printf("\nSetelah Menghapus Data (NPM 240101002)");
    tampilMahasiswa();
    printf("---------------------");
    hapusDepan();
    printf("\nSetelah Menghapus Data di Depan");
    tampilMahasiswa();

    return 0;
}
