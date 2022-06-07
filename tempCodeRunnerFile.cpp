#include <bits/stdc++.h>
using namespace std;

void reverse(int arr[], int low, int high)
{
    if (low < high)
    {
        swap(arr[low], arr[high]);
        reverse(arr, low + 1, high - 1);
    }
}

void print(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}

int main()
{
    int arr[] = {23, 28, 12, 17, 11};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Given Array\n";
    print(arr, n);
    reverse(arr, 0, n - 1);
    cout << "\nReversed Array\n";
    print(arr, n);
    return 0;
}
