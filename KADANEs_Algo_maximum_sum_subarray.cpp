#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,i,j,sum=0,maxSum=INT_MIN;
    cin>>n;
    int arr[n];
    for(i=0;i<n;++i) cin>>arr[i];
    // Normal Approach
    // for(i=0;i<n;++i){
    //     sum=0;
    //     for(j=i;j<n;++j){
    //         sum+=arr[j];
    //         if(sum>maxSum)
    //             maxSum=sum;
    //     }
    // }

    // Better Approach - Kadane's Algorithm
    // Whenever,we get a negative sum we initialize the sum to 0 again
    // Eg. for [-1 4 -6 7 -4] -> maxSum=7
    for(i=0;i<n;++i){
        sum+=arr[i];
        if(sum<0)
            sum=0;
        maxSum=max(maxSum,sum);
    }
    cout<<maxSum;
    return 0;
}