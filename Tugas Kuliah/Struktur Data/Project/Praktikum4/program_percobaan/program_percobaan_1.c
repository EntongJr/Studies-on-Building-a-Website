#include <stdio.h>
#define MAX 10

typedef struct {
    int Item[MAX];
    int Front;
    int Rear;
    int Count;
} Queue;

// Inisialisasi antrian
void Inisialisasi(Queue *q) {
    q->Front = q->Rear = -1;
    q->Count = 0;
}

// Prosedur untuk menyisipkan data pada antrian
void Tambah(Queue *q, int item) {
    if (q->Rear == MAX - 1) {
        printf("\nAntrian Penuh");
        return;
    }

    q->Rear++;
    q->Item[q->Rear] = item;
    q->Count++;
    if (q->Front == -1) q->Front = 0;
}

// Prosedur untuk menghapus data dari antrian
int Hapus(Queue *q) {
    int data;
    if (q->Front == -1) {
        printf("\nAntrian Kosong");
        return -1; // Return -1 to indicate an empty queue
    }

    data = q->Item[q->Front];
    q->Count--;

    if (q->Front == q->Rear) {
        q->Front = q->Rear = -1;
    } else {
        q->Front++;
    }

    return data;
}

void Tampil(Queue *q) {
    if (q->Front == -1) {
        printf("\nAntrian Kosong");
        return;
    }

    for (int i = q->Front; i <= q->Rear; i++) {
        printf("\nData : %d", q->Item[i]);
    }
}

int main() {
    Queue q;
    int data;

    Inisialisasi(&q);
    Tambah(&q, 11);
    Tambah(&q, 12);
    Tambah(&q, 13);
    Tambah(&q, 14);
    Tambah(&q, 15);
    Tambah(&q, 16);
    Tambah(&q, 17);
    Tambah(&q, 18);
    Tambah(&q, 19);
    Tambah(&q, 20);
    Tambah(&q, 21); // This will show "Antrian Penuh" because the queue is full

    Tampil(&q);
    data = Hapus(&q);
    printf("\nHapus Item = %d", data);
    data = Hapus(&q);
    printf("\nHapus Item = %d", data);
    data = Hapus(&q);
    printf("\nHapus Item = %d", data);

    Tampil(&q);
    
    return 0;
}