#include<iostream>
using namespace std;

void reverse(int a[],int n){
    int temp,i=0,j=n-1;
    while(i<j){
        temp=a[i];
        a[i]=a[j];
        a[j]=temp;
        i++;j--;
    }
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i]; //Enter elements 

    reverse(arr,n); //reverse array
    cout<<"The reversed array is: ";
    for(int i=0;i<n;i++) cout<<arr[i]<<" "; //Displating reversed array
    return 0;
}