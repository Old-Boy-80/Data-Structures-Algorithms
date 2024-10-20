#include <stdio.h>
#include <stdlib.h>

// Define a type alias for the Node structure
typedef struct Node {
    int data;               // Data field to store value
    struct Node* next;      // Pointer to the next node
} Node;

// Function prototypes
Node* create();                   // Create a new list
void traverse(Node* head);        // Traverse and print the list
void insert_beg(Node** head, int value); // Insert at the beginning
void insert_end(Node** head, int value); // Insert at the end
void delete_beg(Node** head);     // Delete from the beginning
void delete_end(Node** head);     // Delete from the end

// Main function with menu-driven program
int main() {
    Node* head = NULL;
    int choice, value;

    while (1) {
        printf("\nCircular Singly Linked List Menu:\n");
        printf("1. Create\n");
        printf("2. Traverse\n");
        printf("3. Insert at Beginning\n");
        printf("4. Insert at End\n");
        printf("5. Delete from Beginning\n");
        printf("6. Delete from End\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                head = create();
                break;
            case 2:
                traverse(head);
                break;
            case 3:
                printf("Enter value to insert at beginning: ");
                scanf("%d", &value);
                insert_beg(&head, value);
                break;
            case 4:
                printf("Enter value to insert at end: ");
                scanf("%d", &value);
                insert_end(&head, value);
                break;
            case 5:
                delete_beg(&head);
                break;
            case 6:
                delete_end(&head);
                break;
            case 7:
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}

// Function to create a circular singly linked list
Node* create() {
    int value;
    Node* newNode;
    Node* head = NULL;
    Node* tail = NULL;

    printf("Enter value (enter -1 to stop): ");
    while (1) {
        scanf("%d", &value);
        if (value == -1) break; // Stop input

        newNode = (Node*)malloc(sizeof(Node));
        newNode->data = value;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;     // Initialize head
            tail = newNode;     // Initialize tail
            newNode->next = head; // Point to itself
        } else {
            tail->next = newNode; // Link the new node
            tail = newNode;       // Update tail
            tail->next = head;    // Make it circular
        }
    }
    return head; // Return the head of the list
}

// Function to traverse the circular linked list
void traverse(Node* head) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }
    Node* temp = head;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head); // Continue until we return to the head
    printf("(head)\n");
}

// Function to insert at the beginning
void insert_beg(Node** head, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;

    if (*head == NULL) {
        newNode->next = newNode; // Point to itself
        *head = newNode;         // Update head
    } else {
        Node* tail = *head;
        while (tail->next != *head) {
            tail = tail->next; // Find the last node
        }
        newNode->next = *head; // Link new node to head
        tail->next = newNode;   // Update last node's next
        *head = newNode;        // Update head
    }
}

// Function to insert at the end
void insert_end(Node** head, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;

    if (*head == NULL) {
        newNode->next = newNode; // Point to itself
        *head = newNode;         // Update head
    } else {
        Node* tail = *head;
        while (tail->next != *head) {
            tail = tail->next; // Find the last node
        }
        tail->next = newNode;   // Link last node to new node
        newNode->next = *head;  // Make it circular
    }
}

// Function to delete from the beginning
void delete_beg(Node** head) {
    if (*head == NULL) {
        printf("The list is empty. Cannot delete.\n");
        return;
    }
    Node* temp = *head;
    if (temp->next == *head) { // Only one node in the list
        free(temp);
        *head = NULL; // Update head to NULL
    } else {
        Node* tail = *head;
        while (tail->next != *head) {
            tail = tail->next; // Find the last node
        }
        tail->next = temp->next; // Update last node's next
        *head = temp->next;       // Update head
        free(temp);               // Free old head
    }
}

// Function to delete from the end
void delete_end(Node** head) {
    if (*head == NULL) {
        printf("The list is empty. Cannot delete.\n");
        return;
    }
    Node* temp = *head;
    if (temp->next == *head) { // Only one node in the list
        free(temp);
        *head = NULL; // Update head to NULL
    } else {
        Node* prev = NULL;
        while (temp->next != *head) {
            prev = temp;
            temp = temp->next; // Move to the last node
        }
        prev->next = *head; // Update the second last node's next
        free(temp);         // Free last node
    }
}
