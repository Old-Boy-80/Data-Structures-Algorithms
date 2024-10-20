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

        printf("Enter value of next node: ");
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
