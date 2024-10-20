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

// Deleting a node from the beginning of the linked list
void delete_node_beg(struct Node **s)
{
    if (*s == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    struct Node *tmp = *s;
    *s = tmp->next; // Move head to the next node
    free(tmp); // Free the old head node
    printf("Node with value %d deleted from the beginning.\n", tmp->data);
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

    printf("Enter value of First Node: ");
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

        printf("Press Y to continue or N to Stop: ");
        ch = getchar();
        clear_stdin();

    } while (ch == 'Y' || ch == 'y');

    p->next = NULL; // Terminating our linked list

    printf("\nInitial ");
    traverse_List(s);

    // Deletion of node from the beginning of the linked list
    delete_node_beg(&s);

    printf("\nAfter deletion ");
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
