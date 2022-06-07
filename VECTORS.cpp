#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);

    // v -> 1 2 3

    // traversing using loop
    for(int i=0; i<v.size(); i++) cout<< v[i]<< " ";

    cout<<endl;

    // traversing using iterator
    vector<int>::iterator it;
    for(it=v.begin(); it!=v.end(); it++) cout<< *it<< " ";

    cout<<endl;

    // traversing using auto keyword
    for(auto element:v) cout<< element<< " ";

    v.pop_back(); // v -> 1 2

    vector<int> v2 (3, 50); // v2 -> 50 50 50
    
    cout<<endl;

    swap(v, v2);
    for(auto element:v) cout<< element<< " ";
    for(auto element:v2) cout<< element<< " ";

    sort(v.begin(), v.end());

    // pair
    pair <int, char> p;
    p.first = 3;
    p.second = 'f';
    
    return 0;
}