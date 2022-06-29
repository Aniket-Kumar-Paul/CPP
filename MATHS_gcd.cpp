// gcd(a, b) = gcd(a-b, b) [a > b] -> do until any one is 0
// or, gcd(a, b) = gcd(b, a%b) -> if b = 0 return a

#include <iostream>
using namespace std;

int gcd(int a, int b)
{
    if (b == 0) return a;
    return gcd(b, a%b);
}

int main()
{
    cout << gcd(15, 27) << endl;
    return 0;
}