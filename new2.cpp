#include<bits/stdc++.h>
using namespace std;

long findMaximumSum(vector<int> stockPrice, int k) {
    set<int> se;
    int maxi = 0;
    int s = 0;
    int e = 0;
    int sum = 0;

    while(s<stockPrice.size()){
        auto it=se.find(stockPrice[s]);
        if(it==se.end() && se.size()<k){
            sum += stockPrice[s];
            maxi = max(maxi, sum);
            s++;
        }
        else {
            se.erase(stockPrice[e]);
            sum -= stockPrice[e];
            e++;
        }
    }

    return maxi;
}

int main(){
    vector<int> v = {1,2,7,7,4,3,6};
    cout<<findMaximumSum(v, 3);
}