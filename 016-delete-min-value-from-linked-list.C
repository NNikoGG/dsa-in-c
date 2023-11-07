#include <stdio.h>
#include <stdlib.h>

// Define a structure for a singly linked list node
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* newNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to delete the minimum value node from the linked list
void deleteMin(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node* current = *head;
    struct Node* prev = NULL;
    struct Node* minNode = *head;
    int minValue = (*head)->data;

    while (current != NULL) {
        if (current->data < minValue) {
            minValue = current->data;
            minNode = current;
        }
        current = current->next;
    }

    current = *head;

    // If the minimum value is in the first node
    if (minNode == *head) {
        *head = (*head)->next;
    } else {
        // Traverse the list to find the previous node of the minimum value node
        while (current != minNode) {
            prev = current;
            current = current->next;
        }

        // Update the previous node's next pointer to skip the minimum value node
        prev->next = current->next;
    }

    // Free the memory of the minimum value node
    free(minNode);
}

// Function to print the linked list
void printList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = newNode(10);
    head->next = newNode(5);
    head->next->next = newNode(15);
    head->next->next->next = newNode(2);

    printf("Original linked list:\n");
    printList(head);

    deleteMin(&head);

    printf("Linked list after deleting minimum value:\n");
    printList(head);

    return 0;
}

