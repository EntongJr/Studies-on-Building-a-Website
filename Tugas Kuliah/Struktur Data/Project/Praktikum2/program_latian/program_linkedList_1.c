//Kelompok 13
// 24081010354 Achmad Dimas Saktiawannur Rofiq
// 24081010297 Ali
// 24081010301 ahmadridloabdillah
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


void tampilMahasiswa() {
    struct Mahasiswa *bantu = head;
    if (bantu == NULL) {
        printf("\nList kosong.\n");
        return;
    }
    printf("\nData Mahasiswa:\n");
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
    // Menambahkan data Mahasiswa
    tambahMahasiswa("240101001", "Dimas Sakti");
    tambahMahasiswa("240101002", "Ali");
    tambahMahasiswa("240101003", "Ridho Abdillah");
    tampilMahasiswa();
    
    hapusMahasiswa("240101002");
    printf("\nSetelah dihapus");
    tampilMahasiswa();
    
    return 0;
}
