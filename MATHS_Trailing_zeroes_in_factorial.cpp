#include <iostream>
using namespace std;

int main()
{
    // no. of trailing zeroes = no. of 2x5 pairs = no. of 5's (as there are many 2's but only few 5's which thus can be formed into a formula)
    //                        = floor(n/5) + floor(n/25) + floor(n/125) + ...

    int n, res;
    cin >> n;
    for (int i = 0; i <= n; i = i * 5)
        res = res + n / i;
    cout << res;  
    return 0;
}