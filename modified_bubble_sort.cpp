#include<iostream>
using namespace std;

void swap(int* x, int* y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

void optBubbleSort(int arr[], int n){
    bool swapped;
    for (int i = 0; i < n-1; i++){
        swapped = false;
        for (int j = 0; j < n-i-1; j++){
            if (arr[j] > arr[j+1]){
            swap(&arr[j], &arr[j+1]);
            swapped = true;
            }
        }
        // No elements swapped
        if (swapped == false)
            break;
    }
}
 

int main(){
    int n;
    cout<<"Enter no. of elements in array: ";
    cin>>n;
    int arr[n];
    cout<<"Enter the elements: ";
    for(int i=0;i<n;i++) cin>>arr[i];
    optBubbleSort(arr, n);
    cout<<"\nSorted array is: ";
    for(int i=0;i<n;i++) cout<<arr[i]<<" ";
    return 0;
}