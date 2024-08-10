#include <iostream>

using namespace std;

int main()
{
    int n, arr[100];
    cout << "Enter size of the array between(0-100): ";
    cin >> n;
    if(n < 0 || n > 100)
    {
        cout << "Invalid Size"<<endl;
        return 1;
    }
    cout << "Enter Elements (Sorted Order): " << endl;
    for (int i{0}; i < n; ++i)
    {
        cin >> arr[i];
    }

    int target;
    cout << "Enter Element to Search: ";
    cin >> target;

    cout << endl;

    int low = 0;
    int high = n - 1;
    int mid;
    int found = 0;
    while (low <= high)
    {
        mid = low + (high - low) / 2;
        if (target == arr[mid])
        {
            cout << "Element found at index: " << mid << endl;
            found += 1;
            break;
        }
        else if (target > arr[mid])
        {
            low = mid + 1;
        }
        else if (target < arr[mid])
        {
            high = mid - 1;
        }
    }

    if (found == 0)
    {
        cout << "Element not found" << endl;
    }

    return 0;
}