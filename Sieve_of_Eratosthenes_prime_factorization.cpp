#include<bits/stdc++.h>
using namespace std;

// Find smallest prime factor (spf) -> keep diving the no. by spf until 1
void primeFactor(int n){
    int spf[n]={0};
    for(int i=2;i<=n;i++){
        spf[i]=i;
    }
    for(int i=2;i<=n;i++){
        if(spf[i]==i){
            for(int j=i*i;j<=n;j+=i){
                if(spf[j]==j){
                    spf[j]=i;
                }
            }
        }
    }
    while(n!=1){
        cout<<spf[n]<<" ";
        n=n/spf[n];
    }
}

int main(){
    int n;
    cin>>n;
    primeFactor(n);
    return 0;
}