// given k, and an array, find the maximum for each sliding window of size k in the array
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto &i : a)
        cin >> i;

    // Method 1: O(nlogn).....................................................................
    multiset<int, greater<int>> s; // greater<int> will ensure that the top has the max element
    vector<int> ans;
    for (int i = 0; i < k; i++)
        s.insert(a[i]);
    ans.push_back(*s.begin());

    for (int i = k; i < n; i++)
    {
        s.erase(s.lower_bound(a[i - k])); // to erase only the first occurence of the element
        s.insert(a[i]);
        ans.push_back(*s.begin());
    }
    for (auto i : ans)
        cout << i << " ";
    // ........................................................................................

    // Method 2: O(n)..........................................................................
    deque<int> q;
    vector<int> ans;
    for (int i = 0; i < k; i++)
    {
        while (!q.empty() and a[q.back()] < a[i])
            q.pop_back();
        q.push_back(i);
    }

    ans.push_back(a[q.front()]);
    for (int i = k; i < n; i++)
    {
        if (q.front() == i - k)
        {
            q.pop_front();
        }
        while(!q.empty() and a[q.back()] < a[i]){
            q.pop_back();
        }
        q.push_back(i);
        ans.push_back(a[q.front()]);
    }
    for(auto i: ans)
        cout<<i<<" ";
    // ........................................................................................
    return 0; 
}