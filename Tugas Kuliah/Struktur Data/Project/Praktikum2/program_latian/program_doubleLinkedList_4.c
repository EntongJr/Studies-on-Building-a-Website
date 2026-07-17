// Kelompok 13
// 24081010354 Achmad Dimas Saktiawannur Rofiq
// 24081010297 Ali
// 24081010301 Ahmadridloabdillah

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struktur node Double Linked List
struct Mahasiswa {
    char npm[15];
    char nama[50];
    struct Mahasiswa *next;
    struct Mahasiswa *prev;
};

struct Mahasiswa *head = NULL;
struct Mahasiswa *tail = NULL;

void tambahMahasiswa(char npm[], char nama[]) {
    struct Mahasiswa *baru = (struct Mahasiswa*) malloc(sizeof(struct Mahasiswa));
    strcpy(baru->npm, npm);
    strcpy(baru->nama, nama);
    baru->next = NULL;
    baru->prev = NULL;

    if (head == NULL) {
        head = tail = baru;
    } else {
        tail->next = baru;
        baru->prev = tail;
        tail = baru;
    }
}

void prependMahasiswa(char npm[], char nama[]) {
    struct Mahasiswa *baru = (struct Mahasiswa*) malloc(sizeof(struct Mahasiswa));
    strcpy(baru->npm, npm);
    strcpy(baru->nama, nama);
    baru->next = NULL;
    baru->prev = NULL;

    if (head == NULL) {
        head = tail = baru;
    } else {
        baru->next = head;
        head->prev = baru;
        head = baru;
    }

    printf("\nData %s (%s) berhasil ditambahkan di depan.\n", nama, npm);
}

void hapusMahasiswa(char npm[]) {
    struct Mahasiswa *hapus = head;

    if (head == NULL) {
        printf("\nList kosong, tidak ada data yang bisa dihapus.\n");
        return;
    }

    while (hapus != NULL && strcmp(hapus->npm, npm) != 0) {
        hapus = hapus->next;
    }

    if (hapus == NULL) {
        printf("\nData dengan NPM %s tidak ditemukan.\n", npm);
        return;
    }

    if (hapus == head) {
        head = hapus->next;
        if (head != NULL) head->prev = NULL;
        else tail = NULL; // list jadi kosong
    }
    else if (hapus == tail) {
        tail = hapus->prev;
        tail->next = NULL;
    }
    else {
        hapus->prev->next = hapus->next;
        hapus->next->prev = hapus->prev;
    }

    printf("\nData dengan NPM %s (%s) berhasil dihapus.\n", hapus->npm, hapus->nama);
    free(hapus);
}

void hapusDepan() {
    if (head == NULL) {
        printf("\nList kosong, tidak ada data yang bisa dihapus.\n");
        return;
    }

    struct Mahasiswa *hapus = head;
    head = head->next;

    if (head != NULL)
        head->prev = NULL;
    else
        tail = NULL; // list kosong setelah dihapus

    printf("\nData di depan (%s - %s) berhasil dihapus.\n", hapus->npm, hapus->nama);
    free(hapus);
}

// Menampilkan data dari depan ke belakang
void tampilMahasiswaMaju() {
    struct Mahasiswa *bantu = head;
    if (bantu == NULL) {
        printf("\nList kosong.\n");
        return;
    }
    printf("\nData Mahasiswa (dari depan):\n\n");
    while (bantu != NULL) {
        printf("NPM  : %s\n", bantu->npm);
        printf("Nama : %s\n\n", bantu->nama);
        bantu = bantu->next;
    }
}

// Menampilkan data dari belakang ke depan
void tampilMahasiswaMundur() {
    struct Mahasiswa *bantu = tail;
    if (bantu == NULL) {
        printf("\nList kosong.\n");
        return;
    }
    printf("\nData Mahasiswa (dari belakang):\n\n");
    while (bantu != NULL) {
        printf("NPM  : %s\n", bantu->npm);
        printf("Nama : %s\n\n", bantu->nama);
        bantu = bantu->prev;
    }
}

int main() {
    tambahMahasiswa("240101001", "Dimas Sakti");
    tambahMahasiswa("240101002", "Ali");
    tambahMahasiswa("240101003", "Ridho Abdillah");

    printf("\nData Awal");
    tampilMahasiswaMaju();

    prependMahasiswa("240101000", "Budi Setiawan");
    printf("\nSetelah Menambah di Depan");
    tampilMahasiswaMaju();

    hapusMahasiswa("240101002");
    printf("\nSetelah Menghapus Data (NPM 240101002)");
    tampilMahasiswaMaju();

    hapusDepan();
    printf("\nSetelah Menghapus Data di Depan");
    tampilMahasiswaMaju();

    printf("\nMenampilkan Data dari Belakang");
    tampilMahasiswaMundur();

    return 0;
}
