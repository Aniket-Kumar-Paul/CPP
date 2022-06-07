#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,i,j;
    cin>>n;
    int arr[n];
    for(i=0;i<n;i++){
        cin>>arr[i];
    }

    int idx[n];
    for(i=0;i<n;++i){idx[i]=-1;}
    
    int minidx=INT_MAX;
    for(i=0;i<n;++i){
        if(idx[arr[i]]!=-1)
            minidx=min(minidx,idx[arr[i]]);
        else
            idx[arr[i]]=i;
    }
    if(minidx==INT_MAX)
        cout<<"-1"<<endl;
    else
        cout<<minidx+1<<endl;
    return 0;
}