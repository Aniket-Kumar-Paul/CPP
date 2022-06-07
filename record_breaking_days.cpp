#include<iostream>
#include<limits.h>
using namespace std;

int main(){
    int n,i,records=0;
    cin>>n;
    int arr[n+1];
    for(i=0;i<n;++i){
        cin>>arr[i];
    }
    if(n==1){
        cout<<1;
        return 0;
    }
    arr[n]=-1;
    // __**First Approach**__
    // for(i=0;i<n;++i){
    //     flag=1;
    //     for(j=0;j<=i+1;++j){
    //         if((i!=j) && (j!=n) && (arr[i]<=arr[j])){
    //             flag=0;
    //             break;
    //         }
    //     }
    //     if(flag){
    //         records++;
    //     }
    // }

    // __**Better Approach**__
    int max=-1;
    for(i=0;i<n;++i){
        if(arr[i]>max && arr[i]>arr[i+1]){
            max=arr[i];
            records++;
        }
    }
    cout<<records;
    return 0;
}