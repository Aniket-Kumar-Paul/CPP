#include<iostream>
using namespace std;

void swap(int* x, int* y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

int partition (int arr[], int low, int high) { 
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) { 
            i++;
            swap(&arr[i], &arr[j]); 
        } 
    } 
    swap(&arr[i + 1], &arr[high]); 
    return (i + 1); 
} 

void quickSort(int arr[], int low, int high) { 
    if (low < high) { 
        int pivotIndex = partition(arr, low, high);
        quickSort(arr, low, pivotIndex - 1); 
        quickSort(arr, pivotIndex + 1, high); 
    } 
} 

int main(){
    int n;
    cout<<"Enter no. of elements in array: ";
    cin>>n;
    int arr[n];
    cout<<"Enter the elements: ";
    for(int i=0;i<n;i++) cin>>arr[i];
    quickSort(arr, 0, n-1);
    cout<<"\nSorted array is: ";
    for(int i=0;i<n;i++) cout<<arr[i]<<" ";
    return 0;
}