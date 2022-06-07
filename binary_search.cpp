#include<iostream>
using namespace std;

//Recursive Approach
int binarySearch(int arr[], int low, int high, int key){
    if (high >= low) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == key)
            return mid;
        else if (arr[mid] > key)
            return binarySearch(arr, low, mid - 1, key);
        else
            return binarySearch(arr, mid + 1, high, key);
    }
    return -1;
}

int main(){
    int n, key;
    cout<<"Enter no. of elements in array: ";
    cin>>n;
    int arr[n];
    cout<<"Enter the elements: ";
    for(int i=0;i<n;i++) cin>>arr[i];
    cout<<"Enter element to search: ";
    cin>>key;
    int x = binarySearch(arr, 0, n-1, key);
    if(x == -1)
        cout<<key<<" not found in the array.";
    else
        cout<<key<<" found at position: "<<x+1;
    return 0;
}