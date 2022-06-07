#include<bits/stdc++.h>
using namespace std;

int setBit(int n, int pos){
    return ((n & (1<<pos))!=0);
}

void unique(int arr[], int n){
    int xorsum=0;
    for(int i=0;i<n;i++)
        xorsum=xorsum^arr[i];
    int setbit=0, pos=0, tempxor=xorsum;
    while(setbit!=1){
        setbit=xorsum & 1;
        pos++;
        xorsum=xorsum>>1;
    }
    pos--;
    int newxor=0;
    for(int i=0;i<n;i++){
        if(setBit(arr[i],pos))
            newxor=newxor^arr[i];
    }
    cout<<newxor<<endl;
    cout<<(tempxor^newxor)<<endl;
}

int main(){
    int arr[]={1,2,3,4,3,2,1,6};
    unique(arr,8);
    return 0;
}