#include <stdio.h>
#include <stdlib.h>

#define MAX 5  // Maximum size of the circular queue

// Structure for the Circular Queue
struct CircularQueue {
    int items[MAX];
    int front, rear;
};

// Function to initialize the queue
void initQueue(struct CircularQueue* q) {
    q->front = -1;
    q->rear = -1;
}

// Check if the queue is empty
int isEmpty(struct CircularQueue* q) {
    return (q->front == -1);
}

// Check if the queue is full
int isFull(struct CircularQueue* q) {
    return ((q->rear + 1) % MAX == q->front);
}

// Enqueue (Add element to the queue)
void enqueue(struct CircularQueue* q) {
    if (isFull(q)) {
        printf("Queue is full! Cannot enqueue.\n");
        return;
    }

    int value;
    printf("Enter value to enqueue: ");
    scanf("%d", &value);

    // If the queue is empty, both front and rear are set to 0
    if (q->front == -1) {
        q->front = 0;
    }
    // Circularly move rear to the next position
    q->rear = (q->rear + 1) % MAX;
    q->items[q->rear] = value;
    printf("Enqueued %d\n", value);
}

// Dequeue (Remove element from the front of the queue)
void dequeue(struct CircularQueue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty! Cannot dequeue.\n");
        return;
    }

    int value = q->items[q->front];
    printf("Dequeued %d\n", value);

    // If there is only one element, reset the queue
    if (q->front == q->rear) {
        q->front = q->rear = -1;
    } else {
        // Circularly move front to the next position
        q->front = (q->front + 1) % MAX;
    }
}

// Print the queue
void printQueue(struct CircularQueue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Queue elements: ");
    int i = q->front;
    while (i != q->rear) {
        printf("%d ", q->items[i]);
        i = (i + 1) % MAX;
    }
    printf("%d ", q->items[q->rear]);  // Print the last element
    printf("\n");
}

// Main function with Menu-Driven Program
int main() {
    struct CircularQueue q;
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
