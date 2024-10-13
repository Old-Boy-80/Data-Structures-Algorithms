#include <stdio.h>
#include <stdlib.h>

// Node structure representing an element in the stack
typedef struct Node {
    int data; // data value of the node
    struct Node *next; // Pointer to next node
} Node;


//Stack structure with a pointer to the top node
typedef struct Stack {
    Node* top; // Pointer to the top node in the stack
} Stack;


// Function to create a new stack
Stack* createStack() {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->top = NULL; // Initialize top to NULL
    return stack;
}

// Function to check if the stack is empty
int isEmpty(Stack* stack) {
    return stack->top == NULL; // returns 1 if empty, 0 otherwise
}


//Function to push a new value onto the stack
void push(Stack* stack, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node)); // Allocate memory for a new node
    newNode->data = data; // set the node's data
    newNode->next = stack->top; // Point new node to the current top
    stack->top = newNode; // update top to the new node
    printf("%d value is pushed.\n", data);
}

// Function to pop a value from the stack
int pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack Underflow\n"); // Handle underflow condition
        return -1; // Indicate an error
    }

    Node* tmp = stack->top; // Temporarily hold the top node
    int poppedValue = tmp->data; // Get the data from the top node
    stack->top = stack->top->next; // Mode the top pointer to the next node
    free(tmp); // Free the memory of the popped node
    return poppedValue; // Return the popped value 
}

// Function to print all elements in the stack
void printStack(Stack* stack) {
    if (isEmpty(stack)) {
        printf("No Elements in Stack\n"); // Handle empty case
        return;
    }
    printf("Elements in stack are:\n");
    Node* current = stack->top; // Start from the top node
    while (current != NULL) {
        printf("%d\n", current->data); // Print the data of each node
        current = current->next; // Move to the next node
    }
}

// Function to free all nodes in the stack
void freeStack(Stack* stack) {
    while (!isEmpty(stack)) {
        pop(stack); // Pop all elements to free memory
    }
    free(stack); // Free the stack structure itself
}

// Function to display the menu options
void menu() {
    printf("\nMenu:\n");
    printf("1. PUSH\n");
    printf("2. POP\n");
    printf("3. PRINT\n");
    printf("4. EXIT\n");
}

int main() {
    Stack* stack = createStack(); // Create a new stack
    int choice, value;
    char cont;

    do {
        menu(); // Display the menu
        printf("Enter choice: ");   
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(stack, value);
                break;
            case 2:
                value = pop(stack);
                if (value != -1) {
                    printf("Popped element: %d\n", value); // Display the popped value
                }
                break;
            case 3:
                printStack(stack);
                break;
            case 4:
                freeStack(stack); // Free the stack memory
                printf("Exiting...\n");
                return 0; // Exit the program
            default:
                printf("Invalid choice.\n");
                break;
        }

        printf("Do you want to continue (Y/y)? ");  
        scanf(" %c", &cont);

    } while (cont == 'y' || cont == 'Y'); // Continue while user responds with 'y' or 'Y'

    freeStack(stack); // Free the stack before exiting
    return 0; 
}
