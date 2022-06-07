#include<bits/stdc++.h>
using namespace std;

bool pairsum(int arr[],int n,int k){
    // This approach needs the array to be sorted first
    int low=0,high=n-1;
    while(low<high){
        if(arr[low]+arr[high]==k){
            cout<<low<<" "<<high<<endl;
            return true;
        }
        else if(arr[low]+arr[high]>k){
            high--;
        }
        else{
            low++;
        }
    }
    return false;
}

int main(){
    int n,i,k;
    cin>>n>>k;
    int arr[n];
    for(i=0;i<n;++i) cin>>arr[i];
    cout<<pairsum(arr,n,k)<<endl;
    return 0;
}