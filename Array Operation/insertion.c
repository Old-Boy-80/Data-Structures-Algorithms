#include <stdio.h>

int main()
{

    int arr[100], size, choice;
    printf("Enter size of an array: ");
    scanf("%d", & size);

    printf("Enter elements: \n");
    for(int i =0 ;i < size; ++i)
    {
        scanf("%d", &arr[i]);
    }

    printf("Choices: \n");
    printf("1 - beginning element\n");
    printf("2 - ending element\n");
    printf("3 - your choice element\n");

    printf("Choice: ");
    scanf("%d", &choice);

    if(choice == 1)
    {
        int val;
        printf("Enter value: ");
        scanf("%d", &val);

        for(int i = size; i > 0 ; --i)
        {
            arr[i] = arr[i - 1];
        }
        arr[0] = val;
        size += 1;

    }
    if(choice == 2)
    {
        int val;
        printf("Enter value: ");
        scanf("%d", &val);
        arr[size] = val;
        size+= 1;
    }

    if (choice == 3)
    {
        int pos, val;
        printf("Enter position to change(Index): ");
        scanf("%d", &pos);
        if(pos < 0 || pos > size)
        {
            printf("Enter valid index\n");
        }
        printf("Enter value: ");
        scanf("%d", &val);

        for(int i = size; i > pos; --i)
        {
            arr[i] = arr[i - 1];
        }
        arr[pos] = val;
        size += 1;
    }

    for(int i = 0; i < size; ++i)
    {
        printf("%d ", arr[i]);
    }


    return 0;

}