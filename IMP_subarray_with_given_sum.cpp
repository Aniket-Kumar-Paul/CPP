#include<iostream>
using namespace std;
int main(){
    int n,S,i;
    cin>>n>>S;
    int arr[n];
    for(i=0;i<n;i++){
        cin>>arr[i];
    }

    // Sliding window/Two pointer approach
    int sum=arr[0],start=0;
    for(i=1;i<n;i++){
        while(sum>S && start<i-1){
            sum-=arr[start];
            start++;
        }
        if(sum==S){
            cout<<"\nSum found between indexes : "<<start<<" and "<<i-1;
            return 1;
        }
        if(i<n)
            sum+=arr[i];
    }
    cout<<"No subarray with given sum found";
    return 0;
}