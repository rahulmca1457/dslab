#include <stdio.h>
#include <stdlib.h>

// Function prototypes
void create();
void display();
void insert();
void find();
void delete_node(); // Cleared to use position-based deletion

struct node {                                                                      
    int data;
    struct node *next;
};

// Global head pointer to keep track of the list
struct node *head = NULL;

void main() {
    int choice;
    do {
        printf("\n--- Linked List Operations ---\n");
        printf("1. Create List / Append Node\n2. Display List\n3. Insert Node\n4. Find Node\n5. Delete Node (by Position)\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1: create(); break;
            case 2: display(); break;
            case 3: insert(); break;
            case 4: find(); break;
            case 5: delete_node(); break;
            case 6: exit(0); break;
            default: printf("Invalid choice! Please enter a number between 1 and 6.\n");
        }
    } while(choice != 6);
}

// 1. Create a new list or append elements to the end
void create() {
    struct node *temp, *ptr;
    temp = (struct node *)malloc(sizeof(struct node));
    if (temp == NULL) {
        printf("Out of memory space!\n");
        return;
    }
    
    printf("Enter the data value for the node: ");
    scanf("%d", &temp->data);
    temp->next = NULL;
    
    if (head == NULL) {
        head = temp;
    } else {
        ptr = head;
        while (ptr->next != NULL) {
            ptr = ptr->next;
        }
        ptr->next = temp;
    }
    printf("Node added successfully!\n");
}

// 2. Display all elements in the list
void display() {
    struct node *ptr;
    if (head == NULL) {
        printf("The list is empty!\n");
        return;
    }
    ptr = head;
    printf("List elements: ");
    while (ptr != NULL) {
        printf("%d -> ", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL\n");
}

// 3. Insert a node at a specific position
void insert() {
    struct node *temp, *ptr;
    int pos, i;
    temp = (struct node *)malloc(sizeof(struct node));
    if (temp == NULL) {
        printf("Out of memory space!\n");
        return;
    }
    
    printf("Enter the data to insert: ");
    scanf("%d", &temp->data);
    temp->next = NULL;
    
    printf("Enter the position to insert (1 for beginning): ");
    scanf("%d", &pos);
    
    if (pos == 1) {
        temp->next = head;
        head = temp;
        printf("Node inserted at the beginning!\n");
        return;
    }
    
    ptr = head;
    for (i = 1; i < pos - 1; i++) {
        if (ptr == NULL) {
            printf("Position out of bounds!\n");
            free(temp);
            return;
        }
        ptr = ptr->next;
    }
    
    if (ptr == NULL) {
        printf("Position out of bounds!\n");
        free(temp);
    } else {
        temp->next = ptr->next;
        ptr->next = temp;
        printf("Node inserted successfully!\n");
    }
}

// 4. Find / Search for a specific value and show its position
void find() {
    struct node *ptr;
    int target, pos = 1, found = 0;
    
    if (head == NULL) {
        printf("The list is empty!\n");
        return;
    }
    
    printf("Enter the value to search for: ");
    scanf("%d", &target);
    
    ptr = head;
    while (ptr != NULL) {
        if (ptr->data == target) {
            printf("Element %d found at position %d.\n", target, pos);
            found = 1;
            break;
        }
        ptr = ptr->next;
        pos++;
    }
    if (!found) {
        printf("Element %d not found in the list.\n", target);
    }
}

// 5. Delete a node by its numeric position
void delete_node() {
    struct node *ptr, *prev;
    int pos, i;
    
    if (head == NULL) {
        printf("The list is empty! Nothing to delete.\n");
        return;
    }
    
    printf("Enter the position to delete:");
    scanf("%d", &pos);
    
    if (pos < 1) {
        printf("Invalid position! Positions start from 1.\n");
        return;
    }
    
    ptr = head;
    
    // Case 1: Deleting the first node (head)
    if (pos == 1) {
        head = ptr->next;
        free(ptr);
        printf("Node at position 1 deleted successfully.\n");
        return;
    }
    
    // Traverse to the specified position
    for (i = 1; ptr != NULL && i < pos; i++) {
        prev = ptr;
        ptr = ptr->next;
    }
    
    // Case 2: Position is out of bounds (greater than the list length)
    if (ptr == NULL) {
        printf("Position %d is out of bounds! The list is shorter than that.\n", pos);
        return;
    }
    
    // Case 3: Disconnect the node and free memory
    prev->next = ptr->next;
    free(ptr);
    printf("Node at position %d deleted successfully.\n", pos);
}

