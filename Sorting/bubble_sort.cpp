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

    // bubble Sort
    for (int i{1}; i < n; ++i)
    {
        for (int j{0}; j < n - i; ++j)
        {
            if (arr[j] > arr[j + 1])
            {
                int tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }
    }

    printArray(arr, n);

    return 0;
}