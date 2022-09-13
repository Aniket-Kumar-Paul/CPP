#include<bits/stdc++.h>
using namespace std;

int main() {
    pair<int, string> p;
    // p = make_pair(2, "abc");
    p = {2, "abc"};
    cout << p.first << " " << p.second << endl;

    // copy pair (not by reference)
    pair<int, string> p1 = p;
    p1.first = 5; // doesn't change p.first
    cout << p1.first << " " << p.first << endl;

    // copy pair (by reference)
    pair<int, string> &p2 = p;
    p2.first = 10;  // changes p.first as well
    cout << p2.first << " " << p.first << endl;

    int a[] = {1, 2, 3};
    int b[] = {2, 3, 4};
    pair<int, int> array1[3]; // array of size 3 of type pair<int, int>
    array1[0] = {a[0], b[0]};
    array1[1] = {a[1], b[1]};
    array1[2] = {a[2], b[2]};
    swap(array1[0], array1[2]); // swap pairs
}