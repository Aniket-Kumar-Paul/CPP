#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,i,j,temp;
    cin>>n;
    int arr[n][n];
    for(i=0;i<n;++i){
        for(j=0;j<n;++j)
            cin>>arr[i][j];
    }

    for(i=0;i<n-1;i++){
        for(j=i+1;j<n;j++){
            temp=arr[i][j];
            arr[i][j]=arr[j][i];
            arr[j][i]=temp;
        }
    }
    cout<<"Tranpose of the matrix is :- \n";
    for(i=0;i<n;++i){
        for(j=0;j<n;++j)
            cout<<arr[i][j]<<" ";
        cout<<'\n';
    }
    return 0;
}