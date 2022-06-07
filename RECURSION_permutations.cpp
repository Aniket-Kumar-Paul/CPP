// swap i index with i+1 and ensure to not produce duplicates
// O(n!)
#include <bits/stdc++.h>
using namespace std;

void helper(vector<int> a, vector<vector<int>> &ans, int idx){
    if(idx==a.size()){
        ans.push_back(a);
        return;
    }
    for(int i=idx; i<a.size(); i++){
        if(i!=idx and a[i]==a[idx]) // to remove duplicate permutations
            continue;
        swap(a[i],a[idx]);
        helper(a,ans,idx+1);
    }
}

vector<vector<int>> permute(vector<int> nums){
    sort(nums.begin(),nums.end());
    vector<vector<int>> ans;
    helper(nums,ans,0);
    return ans;
}

int main(){
    int n; cin>>n;
    vector<int> a(n);
    for(auto &i:a) cin>>i;
    vector<vector<int>> ans = permute(a);

    for(auto i:ans){
        for(auto j:i)
            cout<<j<<" ";
        cout<<"\n";
    }

    return 0;
}

// STL Trick
// sort(nums.begin(), nums.end());
// do{
//     ans.push_back(nums);
// }while( next_permutation(nums.begin(), nums.end()) );