#include <stdio.h>
#include <stdlib.h>

// Defining Node
struct Node
{
    int data;
    struct Node *next;
};

// Clearing input buffer
void clear_stdin()
{
    int c;
    while ((c = getchar()) != EOF && c != '\n');
}

// Traversing LinkedList and printing it
void traverse_List(struct Node *s)
{
    struct Node *head = s;

    printf("Linked List: ");
    while (head != NULL)
    {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

// Insertion of a node after a specified node
void insert_node(struct Node *s, int value)
{
    if (s == NULL)
    {
        printf("The list is empty.\n");
        return;
    }

    int preval;
    printf("Enter the value of the previous node after which the new node will be inserted: ");
    scanf("%d", &preval);
    clear_stdin();

    // Search for the node with the given value
    struct Node *prevNode = s;
    while (prevNode != NULL && prevNode->data != preval)
    {
        prevNode = prevNode->next;
    }

    if (prevNode == NULL)
    {
        printf("Node with value %d not found.\n", preval);
        return;
    }

    // Allocate memory for the new node
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        printf("Memory allocation failed\n");
        return;
    }

    // Insert the new node
    newNode->data = value;
    newNode->next = prevNode->next;
    prevNode->next = newNode;

    printf("Node with value %d inserted after node with value %d.\n", value, preval);
}

int main()
{
    struct Node *p, *s, *q;
    char ch;

    // Creating the first node of user's choice
    p = (struct Node *)malloc(sizeof(struct Node));
    if (p == NULL)
    {
        printf("Memory allocation failed\n");
        return -1;
    }

    printf("Enter value of the first node: ");
    scanf("%d", &p->data);
    clear_stdin();

    s = p; // Storing the first node
    p->next = NULL;

    // Creation of dynamic nodes of user's choice
    do
    {
        q = (struct Node *)malloc(sizeof(struct Node));
        if (q == NULL)
        {
            printf("Memory allocation failed\n");
            return -1;
        }

        printf("Enter value of the next node: ");
        scanf("%d", &q->data);
        clear_stdin();

        p->next = q;
        p = q;

        printf("Press Y to continue or N to stop: ");
        ch = getchar();
        clear_stdin();

    } while (ch == 'Y' || ch == 'y');

    p->next = NULL; // Terminating the linked list

    printf("\nInitial ");
    traverse_List(s);

    // Insertion of a new node
    int newVal;
    printf("Enter the value of the new node to insert: ");
    scanf("%d", &newVal);
    insert_node(s, newVal);

    printf("\nAfter insertion ");
    traverse_List(s);

    // Freeing remaining memory
    struct Node *temp;
    while (s != NULL)
    {
        temp = s;
        s = s->next;
        free(temp);
    }

    return 0;
}
