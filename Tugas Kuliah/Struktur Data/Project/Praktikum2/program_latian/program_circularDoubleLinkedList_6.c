// Kelompok 13
// 24081010354 Achmad Dimas Saktiawannur Rofiq=
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

    if (head == NULL) {
        head = tail = baru;
        head->next = head;
        head->prev = head;
    } else {
        baru->prev = tail;
        baru->next = head;
        tail->next = baru;
        head->prev = baru;
        tail = baru;
    }
}

// Tambah node di depan (prepend)
void prependMahasiswa(char npm[], char nama[]) {
    struct Mahasiswa *baru = (struct Mahasiswa*) malloc(sizeof(struct Mahasiswa));
    strcpy(baru->npm, npm);
    strcpy(baru->nama, nama);

    if (head == NULL) {
        head = tail = baru;
        head->next = head;
        head->prev = head;
    } else {
        baru->next = head;
        baru->prev = tail;
        tail->next = baru;
        head->prev = baru;
        head = baru;
    }

    printf("\nData %s (%s) berhasil ditambahkan di depan.\n", nama, npm);
}

// Tampilkan data dari depan ke belakang
void tampilMahasiswa() {
    if (head == NULL) {
        printf("\nList kosong.\n");
        return;
    }

    struct Mahasiswa *bantu = head;
    printf("\nData Mahasiswa (Maju):\n\n");
    do {
        printf("NPM  : %s\n", bantu->npm);
        printf("Nama : %s\n\n", bantu->nama);
        bantu = bantu->next;
    } while (bantu != head);
}

// Tampilkan data dari belakang ke depan
void tampilMundur() {
    if (tail == NULL) {
        printf("\nList kosong.\n");
        return;
    }

    struct Mahasiswa *bantu = tail;
    printf("\nData Mahasiswa (Mundur):\n\n");
    do {
        printf("NPM  : %s\n", bantu->npm);
        printf("Nama : %s\n\n", bantu->nama);
        bantu = bantu->prev;
    } while (bantu != tail);
}

void hapusMahasiswa(char npm[]) {
    if (head == NULL) {
        printf("\nList kosong, tidak ada data yang bisa dihapus.\n");
        return;
    }

    struct Mahasiswa *hapus = head;

    do {
        if (strcmp(hapus->npm, npm) == 0) {
            // Jika hanya 1 node
            if (hapus == head && hapus == tail) {
                head = tail = NULL;
            }
            // Jika hapus head
            else if (hapus == head) {
                head = head->next;
                head->prev = tail;
                tail->next = head;
            }
            // Jika hapus tail
            else if (hapus == tail) {
                tail = tail->prev;
                tail->next = head;
                head->prev = tail;
            }
            // Jika hapus di tengah
            else {
                hapus->prev->next = hapus->next;
                hapus->next->prev = hapus->prev;
            }

            printf("\nData dengan NPM %s (%s) berhasil dihapus.\n", hapus->npm, hapus->nama);
            free(hapus);
            return;
        }
        hapus = hapus->next;
    } while (hapus != head);

    printf("\nData dengan NPM %s tidak ditemukan.\n", npm);
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

    printf("\nTampilkan dari belakang (reverse)");
    tampilMundur();

    return 0;
}
