#include <stdio.h>
#include <stdlib.h>

// Define the Node structure for a doubly linked list
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

// Function to insert a node at the beginning of the list
void insertAtHead(struct Node** head_ref, int new_data) {
    // Allocate memory for the new node
    struct Node* baru = (struct Node*)malloc(sizeof(struct Node));

    // Set the data for the new node
    baru->data = new_data;

    // Make the new node's next to the point current head
    baru->next = *head_ref;
    baru->prev = baru;

    // Move the head to point to the new node
    *head_ref  = baru;
}

// Function  to print the list in forward direction
void printList(struct Node* head){
    struct Node* last;
    printf("Forward Traversal:\n");
    while (head != NULL){
        printf("%d -> ", head->data);
        last = head; //Store the last node to print in reverse later (if needed)
        head = head->next;
    }
    printf("NULL\n");
}

int main(){
    // Start with an existing list of nodes
    struct Node* head = NULL;
    struct Node* kedua = NULL;
    struct Node* ketiga = NULL;

    // Allocate 3 nodes in the heap
    head = (struct Node*)malloc(sizeof(struct Node));
    kedua = (struct Node*)malloc(sizeof(struct Node));
    ketiga = (struct Node*)malloc(sizeof(struct Node));

    // Initialize the nodes and link them
    head->data = 20; //First node
    head->next = kedua;
    head->prev = NULL; //Since it's the head, prev is NULL

    kedua->data = 30; //Second node
    kedua->next = ketiga;
    kedua->prev = head;

    ketiga->data = 40; //Third node
    ketiga->next = NULL;
    ketiga->prev = kedua;

    // Print the exiting doubly linked list
    printf("Original list:\n");
    printList(head);

    // Insert a new node at the begining
    insertAtHead(&head, 10);

    // Print the modified list after insertion
    printf("List after inserting at the begining:\n");
    printList(head);

    return 0;
}