// Kelompok 13
// 24081010354 Achmad Dimas Saktiawannur Rofiq
// 24081010297 Ali
// 24081010301 Ahmadridloabdillah

#include <stdio.h>
#include <string.h>
#include <unistd.h> 

#define MAX 10

struct Proses {
    char kode[10];
    int prioritas;      // Semakin kecil nilainya, semakin tinggi prioritas
    int waktuDatang;    // Waktu proses masuk ke antrian
    int waktuEksekusi;  // Lama waktu yang dibutuhkan CPU
};

struct Proses queue[MAX];
int front = -1, rear = -1;

// Fungsi untuk menambah proses ke antrian (enqueue)
void enqueue(struct Proses p) {
    if (rear == MAX - 1) {
        printf("Antrian penuh!\n");
        return;
    }

    if (front == -1) front = 0;
    rear++;
    queue[rear] = p;
}

// Fungsi untuk menghapus proses dari antrian (dequeue prioritas tertinggi)
struct Proses dequeue() {
    struct Proses temp;
    if (front == -1) {
        printf("Antrian kosong!\n");
        struct Proses kosong = {"-", 0, 0, 0};
        return kosong;
    }

    // Cari proses dengan prioritas tertinggi (angka terkecil)
    int idxPrioritas = front;
    for (int i = front + 1; i <= rear; i++) {
        if (queue[i].prioritas < queue[idxPrioritas].prioritas)
            idxPrioritas = i;
    }

    temp = queue[idxPrioritas];

    // Geser elemen setelah proses yang dihapus
    for (int i = idxPrioritas; i < rear; i++) {
        queue[i] = queue[i + 1];
    }

    rear--;
    if (rear < front) front = rear = -1;

    return temp;
}

// Menampilkan isi antrian
void tampilkanQueue() {
    if (front == -1) {
        printf("Antrian kosong.\n");
        return;
    }

    printf("Isi Antrian (kode - prioritas - datang - durasi):\n");
    for (int i = front; i <= rear; i++) {
        printf("  %s | P:%d | Tiba:%d | Waktu:%d\n",
            queue[i].kode,
            queue[i].prioritas,
            queue[i].waktuDatang,
            queue[i].waktuEksekusi);
    }
    printf("\n");
}

int main() {
    int waktuCPU = 0;

    struct Proses p1 = {"P1", 2, 1, 3};
    struct Proses p2 = {"P2", 1, 2, 4};
    struct Proses p3 = {"P3", 3, 3, 2};
    struct Proses p4 = {"P4", 1, 4, 3};

    enqueue(p1);
    enqueue(p2);
    enqueue(p3);
    enqueue(p4);

    printf("SIMULASI KINERJA CPU DENGAN QUEUE\n");
    tampilkanQueue();

    while (front != -1) {
        struct Proses current = dequeue();
        printf("\nMenjalankan proses %s (Prioritas %d)...\n", current.kode, current.prioritas);

        for (int t = 0; t < current.waktuEksekusi; t++) {
            waktuCPU++;
            printf("Waktu CPU: %d detik\n", waktuCPU);
            sleep(1);
        }

        printf("Proses %s selesai\n", current.kode);
        printf("\nKondisi antrian setelah refresh:\n");
        tampilkanQueue();
    }

    printf("\nSemua proses telah selesai dijalankan\n");
    printf("Total waktu CPU digunakan: %d detik\n", waktuCPU);

    return 0;
}
