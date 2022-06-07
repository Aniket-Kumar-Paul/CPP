#include<iostream>
using namespace std;
int main(){
    int n,i,j,sum;
    cin>>n;
    int arr[n];
    for(i=0;i<n;i++){
        cin>>arr[i];
    }
    for(i=0;i<n;++i){
        sum=0;
        for(j=i;j<n;++j){
            sum+=arr[j];
            cout<<sum<<endl;
        }
    }
    return 0;
}