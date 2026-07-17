// Kelompok 13
// 24081010354 Achmad Dimas Saktiawannur Rofiq
// 24081010297 Ali
// 24081010301 Ahmad ridlo abdillah

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Mahasiswa {
    char npm[15];
    char nama[50];
    struct Mahasiswa *next;
};

struct Mahasiswa *head = NULL;
struct Mahasiswa *tail = NULL;

void tambahMahasiswa(char npm[], char nama[]) {
    struct Mahasiswa *baru = (struct Mahasiswa*) malloc(sizeof(struct Mahasiswa));
    strcpy(baru->npm, npm);
    strcpy(baru->nama, nama);

    if (head == NULL) {
        head = tail = baru;
        baru->next = head; // circular
    } else {
        tail->next = baru;
        tail = baru;
        tail->next = head; // circular
    }
}

void prependMahasiswa(char npm[], char nama[]) {
    struct Mahasiswa *baru = (struct Mahasiswa*) malloc(sizeof(struct Mahasiswa));
    strcpy(baru->npm, npm);
    strcpy(baru->nama, nama);

    if (head == NULL) {
        head = tail = baru;
        baru->next = head;
    } else {
        baru->next = head;
        head = baru;
        tail->next = head; // sambungkan tail ke head baru
    }

    printf("\nData %s (%s) berhasil ditambahkan di depan.\n", nama, npm);
}

void tampilMahasiswa() {
    if (head == NULL) {
        printf("\nList kosong.\n");
        return;
    }

    struct Mahasiswa *bantu = head;
    printf("\nData Mahasiswa:\n\n");
    do {
        printf("NPM  : %s\n", bantu->npm);
        printf("Nama : %s\n\n", bantu->nama);
        bantu = bantu->next;
    } while (bantu != head); // berhenti jika sudah kembali ke head
}

void hapusMahasiswa(char npm[]) {
    if (head == NULL) {
        printf("\nList kosong, tidak ada data yang bisa dihapus.\n");
        return;
    }

    struct Mahasiswa *hapus = head, *bantu = tail;
    int found = 0;

    do {
        if (strcmp(hapus->npm, npm) == 0) {
            found = 1;
            break;
        }
        bantu = hapus;
        hapus = hapus->next;
    } while (hapus != head);

    if (!found) {
        printf("\nData dengan NPM %s tidak ditemukan.\n", npm);
        return;
    }

    if (head == tail && strcmp(head->npm, npm) == 0) {
        free(head);
        head = tail = NULL;
        printf("\nData dengan NPM %s berhasil dihapus (list sekarang kosong).\n", npm);
        return;
    }

    if (hapus == head) {
        head = head->next;
        tail->next = head;
        free(hapus);
    }
    else if (hapus == tail) {
        bantu->next = head;
        tail = bantu;
        free(hapus);
    }
    else {
        bantu->next = hapus->next;
        free(hapus);
    }

    printf("\nData dengan NPM %s berhasil dihapus.\n", npm);
}

int main() {
    tambahMahasiswa("240101001", "Dimas Sakti");
    tambahMahasiswa("240101002", "Ali");
    tambahMahasiswa("240101003", "Ridho Abdillah");

    printf("\nData Awal");
    tampilMahasiswa();

    prependMahasiswa("240101000", "Budi Setiawan");
    printf("\nSetelah Ditambah di Depan");
    tampilMahasiswa();

    hapusMahasiswa("240101002");
    printf("\nSetelah Menghapus Data");
    tampilMahasiswa();

    return 0;
}
