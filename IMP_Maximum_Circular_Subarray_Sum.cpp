#include<iostream>
#include<climits>
using namespace std;

int kadane(int arr[],int n){
    int currentsum=0;
    int maxsum=INT_MIN;
    for(int i=0;i<n;i++){
        currentsum+=arr[i];
        if(currentsum<0)
            currentsum=0;
        maxsum=max(maxsum,currentsum);
    }
    return maxsum;
}

int main(){
    int n,i;
    cin>>n;
    int arr[n];
    for(i=0;i<n;++i) cin>>arr[i];
    // maxSum can be either wrapping where circular elements are also included or non-wrapping
    // For nonwrapping, simply use kadanes algorithm, for wrapping see below:-
    // Eg: [4 -4 6 -6 10 -11 12] -> maxSum=22, from 12 to 10(circular)
    // 4 -4 6 -6 10 12 are contributing/wrapping elements
    // -11 is non-contributing/non-wrapping element
    // **[wrapSum = total sum of array - sum of non contributing elements]**
    // OR, **[wrapSum = total sum of array + sum of non contributing elements(for elements reversed to find sum using kadanes algo)]** 
    // To find sum of non contributing element :-
    //      -> Reverse sign of all elements
    //      -> Find max subarray of the reversed elements array using Kadane's Algo.
    int wrapsum,nonwrapsum;
    nonwrapsum=kadane(arr,n);
    int totalsum=0;
    for(i=0;i<n;i++){
        totalsum+=arr[i];
        arr[i]=-arr[i]; //reversing sign
    } 
    wrapsum = totalsum + kadane(arr,n); //kadane of the reversed sign elements array
    cout<<max(wrapsum,nonwrapsum)<<endl;
    return 0;
}