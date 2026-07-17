#include <stdio.h>
#include <stdlib.h>

// Struktur node untuk linked list
typedef struct Node {
    int data;
    int priority;
    struct Node* next;
} Node;

// Fungsi untuk membuat node baru
Node* createNode(int data, int priority) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->priority = priority;
    newNode->next = NULL;
    return newNode;
}

// Fungsi untuk menambah elemen ke priority queue
void enqueue(Node** head, int data, int priority) {
    Node* newNode = createNode(data, priority);

    // Jika queue kosong atau prioritas baru lebih tinggi dari head
    if (*head == NULL || (*head)->priority < priority) {
        newNode->next = *head;
        *head = newNode;
    } else {

    // Cari posisi yang sesuai untuk memasukkan elemen baru
    Node* temp = *head;
        while (temp->next != NULL && temp->next->priority >=priority) {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
    printf("Elemen %d dengan prioritas %d ditambahkan ke queue.\n", data, priority);
}

// Fungsi untuk menghapus elemen dengan prioritas tertinggi
int dequeue(Node** head) {
    if (*head == NULL) {
        printf("Priority Queue kosong!\n");
        return -1;
    }
    Node* temp = *head;
    int data = temp->data;
    *head = (*head)->next;
    free(temp);
    return data;
}

// Fungsi untuk menampilkan elemen dalam priority queue
void displayQueue(Node* head) {
    if (head == NULL) {
        printf("Priority Queue kosong!\n");
        return;
    }
    Node* temp = head;
    printf("Isi Priority Queue: \n");
    while (temp != NULL) {
        printf("Data: %d, Prioritas: %d\n", temp->data, temp->priority);
        temp = temp->next;
    }
}

int main() {
    Node* pq = NULL;
    enqueue(&pq, 4, 1);
    enqueue(&pq, 5, 2);
    enqueue(&pq, 6, 0);
    enqueue(&pq, 7, 3);

    displayQueue(pq);

    printf("Elemen dengan prioritas tertinggi yang dihapus: %d\n", dequeue(&pq));
    printf("Elemen dengan prioritas tertinggi yang dihapus: %d\n", dequeue(&pq));

    displayQueue(pq);
    
    return 0;
}
