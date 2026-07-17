#include <stdio.h>
#include <stdlib.h>

// Definisi struktur node untuk single linked list
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Definisi queue menggunakan single linked list
typedef struct {
    Node* front;
    Node* rear;
} Queue;

// Inisialisasi queue
void InitializeQueue(Queue* q) {
    q->front = NULL;
    q->rear = NULL;
}

// Mengecek apakah queue kosong
int IsEmpty(Queue* q) {
    return (q->front == NULL);
}

// Menambah elemen ke queue (enqueue)
void Enqueue(Queue* q, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Heap overflow! Gagal menambahkan elemen ke queue.\n");
        return;
    }
    newNode->data = value;
    newNode->next = NULL;

    if (IsEmpty(q)) {
        q->front = newNode;
    } else {
        q->rear->next = newNode;
    }
    q->rear = newNode;
    printf("Elemen %d ditambahkan ke queue.\n", value);
}

// Menghapus elemen dari queue (dequeue)
int Dequeue(Queue* q) {
    if (IsEmpty(q)) {
        printf("Queue kosong! Tidak ada elemen yang dapat dihapus.\n");
        return -1;
    }

    Node* temp = q->front;
    int value = temp->data;
    q->front = q->front->next;

    if (q->front == NULL) {
        q->rear = NULL;
    }
    free(temp);
    printf("Elemen %d dihapus dari queue.\n", value);
    return value;
}

// Menampilkan elemen dalam queue
void DisplayQueue(Queue* q) {
    if (IsEmpty(q)) {
        printf("Queue kosong!\n");
        return;
    }
    Node* temp = q->front;
    printf("Isi queue: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Fungsi utama untuk menguji implementasi queue dengan single linked list
int main() {
    Queue q;
    InitializeQueue(&q);

    Enqueue(&q, 10);
    Enqueue(&q, 20);
    Enqueue(&q, 30);
    DisplayQueue(&q);

    Dequeue(&q);
    DisplayQueue(&q);
    
    return 0;
}
