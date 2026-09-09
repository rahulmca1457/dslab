#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define a Node structure
struct Node {
    int data;
    struct Node* next;
};

// Global top pointer
struct Node* top = NULL;

// Function declarations
void push(int value);
void pop();
int peek();
bool isEmpty();
void display();

int main() {
    int choice, value;
    bool running = true;

    // The while loop keeps the program running until the user chooses to exit
    while (choice!=5) {
        printf("\n--- STACK OPERATIONS ---\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display Stack\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(value);
                break;
            case 2:
                pop();
                break;
            case 3:
                value = peek();
                if (value != -1) {
                    printf("Top element is: %d\n", value);
                }
                break;
            case 4:
                display();
                break;
            case 5:
                printf("Exiting program and freeing memory...\n");
                running = false; // Breaks the while loop
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

}

// Push: Insert an element onto the stack
void push(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("stack Overflow");
        return;
    }
    newNode->data = value;
    newNode->next = top;
    top = newNode;
    printf("successfully pushed");
}

// Pop: Remove the top element from the stack
void pop() {
    if (top==NULL) {
        printf("Stack Underflow! Nothing to pop.\n");
        return;
    }
    struct Node* temp = top;
    top = top->next;
    printf("%d popped from the stack.\n", temp->data);
    free(temp);
}

// Peek: Return the top element
int peek() {
    if (top==NULL) {
        printf("Stack is empty.\n");
        return -1;
    }
    return top->data;
}


// Display stack elements
void display() {
    if (top==NULL) {
        printf("Stack is empty.\n");
        return;
    }
    struct Node* temp = top;
    printf("Stack status (Top -> Bottom): ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

