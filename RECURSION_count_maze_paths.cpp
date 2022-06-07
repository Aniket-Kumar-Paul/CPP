#include<iostream>
using namespace std;

int countMazePath(int r, int c){
    if(r==1||c==1) return 1;
    return countMazePath(r-1,c)+countMazePath(r,c-1);
}

int main(){
    cout<<countMazePath(3,3);
    return 0;
}