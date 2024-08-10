#include <stdio.h>

int main()
{

    int n, arr[100];

    printf("Enter no.of elements: ");
    scanf("%d", &n);

    printf("Enter elements of array: \n");
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int target;
    int found = -1;

    printf("Enter target element: ");
    scanf("%d", &target);

    for(int i = 0; i < n; i++)
    {
        if(arr[i] == target)
        {
            found = i;
            break;
        }
    }

    if(found != -1)
    {
        printf("Element found at index %d\n", found);
    }
    else
    {
        printf("Element not found\n");
    }

    return 0;
}