#include<iostream>
using namespace std;

void swap(int* x, int* y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

void selectionSort(int arr[], int n){
    int i, j, minIndex;
    for (i = 0; i < n-1; i++){
        minIndex = i;
        for (j = i+1; j < n; j++){
            if (arr[j] < arr[minIndex])
                minIndex = j;
        }
        swap(&arr[minIndex], &arr[i]);
    }
}

int main(){
    int n;
    cout<<"Enter no. of elements in array: ";
    cin>>n;
    int arr[n];
    cout<<"Enter the elements: ";
    for(int i=0;i<n;i++) cin>>arr[i];
    selectionSort(arr, n);
    cout<<"\nSorted array is: ";
    for(int i=0;i<n;i++) cout<<arr[i]<<" ";
    return 0;
}