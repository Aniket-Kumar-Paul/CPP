#include<iostream>
using namespace std;
int main(){
    int n,i,j,diff,max,counter;
    cin>>n;
    int arr[n];
    for(i=0;i<n;i++){
        cin>>arr[i];
    }
    diff=arr[1]-arr[0];
    counter=2;
    max=2;
    for(i=1;i<n-1;i++){
        if(arr[i+1]-arr[i]==diff){
            counter++;
            if(counter>max)
            max=counter;
        }
        else{
            diff=arr[i+1]-arr[i];
            counter=2;
        }
    }
    cout<<max;
    return 0;
}