#include <stdio.h>

#define MAX 10 // Define the maximum size of the stack
int stack[MAX]; // Array to hold stack elements
int top = -1; // Variable to track the index of the top element

// Function to display the menu options
void menu() {
    printf("\nMenu:\n1. PUSH\n2. POP\n3. PRINT\n4. EXIT\n");
}

// Function to push an element onto the stack
void PUSH() {
    if (top >= MAX - 1) { // Check for stack overflow
        printf("Stack Overflow\n");
        return; // Exit if the stack is full
    }
    top += 1; // Increment top index
    printf("Enter value to push: ");
    int a;
    scanf("%d", &a); // Read value to push
    printf("%d value is pushed.\n", a);
    stack[top] = a; // Place the value on top of the stack
}

// Function to pop an element from the stack
void POP() {
    if (top < 0) { // Check for stack underflow
        printf("Stack Underflow\n");
        return; // Exit if the stack is empty
    }
    printf("Popped element: %d\n", stack[top]); // Display the popped value
    top -= 1; // Decrement top index
}

// Function to print all elements in the stack
void PRINT() {
    if (top == -1) { // Check if the stack is empty
        printf("No Element in Stack\n");
        return; // Exit if the stack is empty
    }
    printf("Elements in stack are:\n");
    for (int i = top; i >= 0; i--) { // Iterate from top to bottom
        printf("%d \n", stack[i]); // Print each element
    }
}

// Main function to drive the stack operations
int main() {
    char ch; // Variable to continue or exit
    do {
        menu(); // Display the menu
        int choice;
        printf("Enter choice: ");
        scanf("%d", &choice); // Read user's choice

        switch (choice) {
            case 1:
                PUSH(); // Call push function
                break;
            case 2:
                POP(); // Call pop function
                break;
            case 3:
                PRINT(); // Call print function
                break;
            case 4:
                printf("Exiting...\n");
                return 0; // Exit the program
            default:
                printf("Invalid Choice\n"); // Handle invalid choice
                break;
        }

        printf("\nDo you want to continue (Y/y): ");
        scanf(" %c", &ch); // Read continuation response

    } while (ch == 'y' || ch == 'Y'); // Continue if the user enters 'y' or 'Y'
    
    return 0; // Return from main
}
