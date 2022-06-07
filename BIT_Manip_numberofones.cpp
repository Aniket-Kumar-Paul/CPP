#include<bits/stdc++.h>
using namespace std;

int numberofones(int n){
    int count=0;
    while(n){
        n=(n & n-1);
        count++;
    }
    return count;
}

int main(){
    cout<<"Number of ones in 14 is "<<numberofones(14);
    return 0;
}