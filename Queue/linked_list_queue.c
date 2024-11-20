#include <stdio.h>
#include <stdlib.h>

// Structure for the Queue Node
struct Node {
    int data;
    struct Node* next;
};

// Structure for the Queue
struct Queue {
    struct Node* front;  // Points to the front of the queue
    struct Node* rear;   // Points to the rear of the queue
};

// Function to initialize the queue
void initQueue(struct Queue* q) {
    q->front = q->rear = NULL;
}

// Check if the queue is empty
int isEmpty(struct Queue* q) {
    return (q->front == NULL);
}

// Enqueue (Add element to the rear of the queue)
void enqueue(struct Queue* q) {
    int value;
    printf("Enter value to enqueue: ");
    scanf("%d", &value);

    // Create a new node
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    // If the queue is empty, the new node will be both the front and rear
    if (q->rear == NULL) {
        q->front = q->rear = newNode;
        printf("Enqueued %d\n", value);
        return;
    }

    // Otherwise, add the new node at the rear and update the rear pointer
    q->rear->next = newNode;
    q->rear = newNode;
    printf("Enqueued %d\n", value);
}

// Dequeue (Remove element from the front of the queue)
void dequeue(struct Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty! Cannot dequeue.\n");
        return;
    }

    struct Node* temp = q->front;
    int value = temp->data;
    
    // Move the front pointer to the next node
    q->front = q->front->next;

    // If the front becomes NULL, also set the rear to NULL (queue is empty)
    if (q->front == NULL) {
        q->rear = NULL;
    }

    free(temp);  // Free the memory of the dequeued node
    printf("Dequeued %d\n", value);
}

// Print the entire queue
void printQueue(struct Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
        return;
    }

    struct Node* temp = q->front;
    printf("Queue elements: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Main function with Menu-Driven Program
int main() {
    struct Queue q;
    initQueue(&q);  // Initialize the queue

    int choice;

    do {
        printf("\nMenu:\n");
        printf("1. Add (Enqueue)\n");
        printf("2. Delete (Dequeue)\n");
        printf("3. Print Queue\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                enqueue(&q);  // Add element to the queue
                break;
            case 2:
                dequeue(&q);  // Remove element from the queue
                break;
            case 3:
                printQueue(&q);  // Print all elements in the queue
                break;
            case 4:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}
