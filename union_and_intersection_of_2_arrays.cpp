#include<iostream>
#include<algorithm>
using namespace std;

void Union(int arr1[], int arr2[], int n)
{
    int i = 0, j = 0;
    while (i < n && j < n) {
        if (arr1[i] < arr2[j])
            cout << arr1[i++] << " ";
 
        else if (arr2[j] < arr1[i])
            cout << arr2[j++] << " ";
 
        else {
            cout << arr2[j++] << " ";
            i++;
        }
    }
    // Printing remaining elements of both arrays
    while (i < n)
        cout << arr1[i++] << " ";
 
    while (j < n)
        cout << arr2[j++] << " ";
}

void Intersection(int arr1[], int arr2[], int n)
{
    int i = 0, j = 0;
    while (i < n && j < n) {
        if (arr1[i] < arr2[j])
            i++;
        else if (arr2[j] < arr1[i])
            j++;
        else /* if arr1[i] == arr2[j] */
        {
            cout << arr2[j] << " ";
            i++;
            j++;
        }
    }
}

int main(){
    int n;
    cin>>n;
    int arr1[n],arr2[n];
    cout<<"Enter elements for array 1: ";
    for(int i=0;i<n;i++) cin>>arr1[i];
    cout<<"\nEnter elements for array 2: ";
    for(int i=0;i<n;i++) cin>>arr2[i];

    //Sorting both the arrays
    sort(arr1,arr1+n);
    sort(arr2,arr2+n);

    //Union
    cout<<"Union of the two array : ";
    Union(arr1,arr2,n);
    
    //Intersection
    cout<<"\nIntersection of the two array : ";
    Intersection(arr1,arr2,n);
    return 0;
}
