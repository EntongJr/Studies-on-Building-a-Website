#include <stdio.h>

struct Node {
    int data;
    struct Node* next;
};

void printList(struct Node* head){
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main(){
    // Deklarasi dan Inisialisasi node-node
    struct Node n1, n2, n3;

    // Isi data dan hubungkan node-node
    n1.data = 10;
    n1.next = &n2;

    n2.data = 20;
    n2.next = &n3;

    n3.data = 30;
    n3.next = NULL;

    // Cetak Linked List
    printList(&n1);
    return 0;
}