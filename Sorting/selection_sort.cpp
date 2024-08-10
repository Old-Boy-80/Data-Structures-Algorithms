#include <iostream>

using namespace std;

void printArray(int arr[], int n)
{
    for (int i{0}; i < n; ++i)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int n, arr[100];

    cout << "Enter size of array(between 0-100): ";
    cin >> n;

    if (n < 0 || n > 100)
    {
        cout << "Invalid size" << endl;
        return 1;
    }

    cout << "Enter elements: " << endl;
    for (int i{0}; i < n; ++i)
    {
        cin >> arr[i];
    }

    printArray(arr, n);

    // Selection sort
    for (int i{0}; i < n - 1; ++i)
    {
        int pos = i;
        for (int j{i + 1}; j < n; ++j)
        {
            if (arr[pos] > arr[j])
            {
                pos = j;
            }
        }

        // Swap
        if (pos != i)
        {
            int temp = arr[i];
            arr[i] = arr[pos];
            arr[pos] = temp;
        }
    }

    printArray(arr, n);

    return 0;
}