#include<bits/stdc++.h>
using namespace std;

// (vector<int> v) --> v is taken by value not by reference (a copy of vector is passed to the function)
// so, use & (by reference)
void printVector(vector<int> &v) { 
    // v.size() --> O(1)
    for(int i=0; i<v.size(); i++)
        cout << v[i] << " ";
    cout << endl;
}

int main() {
    vector<int> v;
    v.push_back(5); // O(1)
    v.push_back(7);
    printVector(v);

    vector<int> v1(10, 5); // v1 has 10 5's already in it (by default 0, if 5 not given)
    v1.push_back(7); // 5 5 5 5 5 5 5 5 5 5 7
    v1.pop_back(); // pop last element

    vector<int> v2 = v1; // copy vector (not by reference) O(n)
    vector<int> &v3 = v1; // copy vector (by reference) 0(1)
} 