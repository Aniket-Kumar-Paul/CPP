#include<iostream>
#include<cmath>
using namespace std;

int coinMax(int a[], int l, int r){
    if(l+1==r) return max(a[l],a[r]);
    return max(a[l]+min(coinMax(a,l+2,r),coinMax(a,l+1,r-1)),a[r]+min(coinMax(a,l+1,r-1),coinMax(a,l,r-2)));
}

int main(){
    int arr[]={1, 5, 7, 3, 2, 4};
    int size = 6;
    cout<<coinMax(arr, 0, size-1);
    return 0;
}
