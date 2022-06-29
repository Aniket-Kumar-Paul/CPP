#include <iostream>
using namespace std;

long fastPower(long a, long b, int n)
{
    long res = 1;
    while (b > 0)
    {
        if (b && 1 != 0)
        {
            // res = (res%n * a%n) % n
            res = (res * a % n) % n; // since res is always smaller than n => res%n = res
        }
        a = (a % n * a % n) % n;
        b = b >> 1;
    }
    return res;
}

int main() {
    cout<<fastPower(387987, 6, 1000000007); 
    return 0;
}