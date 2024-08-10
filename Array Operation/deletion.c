#include <stdio.h>

int main()
{
    int arr[100];
    int size, choice;
    printf("Enter size of an array: ");
    scanf("%d", &size);

    printf("Enter Elements:\n");
    for (int i = 0; i < size; ++i)
    {
        scanf("%d", &arr[i]);
    }

    printf("Choices:\n");
    printf("1 -- Delete Beginning Element\n");
    printf("2 -- Delete Ending Element\n");
    printf("3 -- Delete specific Element: \n");

    printf("Choice: ");
    scanf("%d", &choice);

    if (choice == 1)
    {
        for (int i = 1; i < size; ++i)
        {
            arr[i - 1] = arr[i];
        }
        size -= 1;
    }
    else if (choice == 2)
    {
        for (int i = 0; i < size - 1; ++i)
        {
            arr[i] = arr[i];
        }
        size -= 1;
    }
    else if (choice == 3)
    {
        int pos;
        printf("Enter position(Index): ");
        scanf("%d", &pos);
        if (pos < 0 || pos > size)
        {
            printf("Enter correct index position\n");
            return 1;
        }
        for (int i = pos; i < size; ++i)
        {
            arr[i] = arr[i + 1];
        }
        size -= 1;
    }

    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}