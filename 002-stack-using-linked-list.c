#include <stdio.h>
#include <stdlib.h>

// Define a structure for a node in the linked list
struct node {
    int val;
    struct node *next;
};

// Declare a pointer to the head of the linked list
struct node *head;

// Function to push an element onto the stack
void push() {
    int val;
    struct node *ptr = (struct node*)malloc(sizeof(struct node));

    if (ptr == NULL) {
        printf("not able to push the element\n");
    } else {
        printf("Enter the value\n");
        scanf("%d", &val);

        if (head == NULL) {
            // If the stack is empty, create the first node
            ptr->val = val;
            ptr->next = NULL;
            head = ptr;
        } else {
            // If the stack is not empty, add a new node at the top
            ptr->val = val;
            ptr->next = head;
            head = ptr;
        }

        printf("Item %d is pushed\n", val);
    }
}

// Function to pop an element from the stack
void pop() {
    struct node *ptr;
    int item;

    if (head == NULL) {
        printf("Underflow\n");
    } else {
        // Remove the top element from the stack and free its memory
        item = head->val;
        ptr = head;
        head = head->next;
        free(ptr);
        printf("Item %d is Popped\n", item);
    }
}

// Function to display the elements in the stack
void display() {
    struct node *ptr;
    ptr = head;

    if (head == NULL) {
        printf("Stack is Empty\n");
    } else {
        printf("Printing the elements: \n");
        while (ptr != NULL) {
            printf("%d\n", ptr->val);
            ptr = ptr->next;
        }
    }
}

int main() {
    int choice;

    printf("Main Menu\n");

    // Initialize a menu and handle user choices
    while (choice != 4) {
        printf("1. PUSH\n");
        printf("2. POP\n");
        printf("3. DISPLAY\n");
        printf("4. EXIT\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting the program....");
                break;
            default:
                printf("Please Enter Valid Choice 1-4: \n");
        }
    }
}
