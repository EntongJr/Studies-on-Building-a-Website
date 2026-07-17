#include <stdio.h>

// Define the Node structure for a doubly linked list
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

// Function to print the list in forward direction
void printList(struct Node* head) {
    struct Node* last;
    printf("Forward Traversal:\n");
    while (head != NULL) {
        printf("%d -> ", head->data);
        last = head; // Store the last node to print in reverse later
        head = head->next;
    }
    printf("NULL\n");

    // Print list in reverse direction
    printf("Reverse Traversal:\n");
    while (last != NULL) {
        printf("%d -> ", last->data);
        last = last->prev;
    }
    printf("NULL\n");
}

int main() {
    // Declare and initialize nodes
    struct Node n1, n2, n3;

    // Initialize data and set up next and prev pointers
    n1.data = 10;
    n1.next = &n2;
    n1.prev = NULL;

    n2.data = 20;
    n2.next = &n3;
    n2.prev = &n1;

    n3.data = 30;
    n3.next = NULL;
    n3.prev = &n2;

    // Print the doubly linked list
    printList(&n1);
    
    return 0;
}