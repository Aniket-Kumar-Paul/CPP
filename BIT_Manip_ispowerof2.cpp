#include<bits/stdc++.h>
using namespace std;

bool ispowerof2(int n){
    if(n==0)
        return false;
    return !(n & n-1);
}

int main(){
    cout<<ispowerof2(8);
    return 0;
}