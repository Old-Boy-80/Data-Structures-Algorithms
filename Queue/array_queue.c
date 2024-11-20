#include <stdio.h>
#include <stdlib.h>

#define MAX 5  // Size of the queue

// Define the structure of the queue
struct Queue {
    int items[MAX];
    int front, rear;
};

// Initialize the queue
void initQueue(struct Queue* q) {
    q->front = -1;
    q->rear = -1;
}

// Check if the queue is empty
int isEmpty(struct Queue* q) {
    return (q->front == -1);
}

// Check if the queue is full
int isFull(struct Queue* q) {
    return (q->rear == MAX - 1);
}

// Enqueue (Add an element to the queue)
void enqueue(struct Queue* q) {
    if (isFull(q)) {
        printf("Queue is full! Cannot add more elements.\n");
        return;
    }
    int value;
    printf("Enter value to enqueue: ");
    scanf("%d", &value);

    if (q->front == -1) {
        q->front = 0;  // First element being added
    }
    q->rear++;
    q->items[q->rear] = value;
    printf("Enqueued %d\n", value);
}

// Dequeue (Remove an element from the queue)
void dequeue(struct Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty! Cannot dequeue.\n");
        return;
    }
    int value = q->items[q->front];
    printf("Dequeued %d\n", value);
    // Shift all elements to the left
    for (int i = q->front; i < q->rear; i++) {
        q->items[i] = q->items[i + 1];
    }
    q->rear--;
    if (q->rear == -1) {
        q->front = -1;  // Reset to -1 when queue becomes empty
    }
}

// Print the queue
void printQueue(struct Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue elements: ");
    for (int i = q->front; i <= q->rear; i++) {
        printf("%d ", q->items[i]);
    }
    printf("\n");
}

// Main function with the menu-driven program
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
