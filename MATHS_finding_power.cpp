// a^b = (a^2)^b/2  , if b is even
//     = a.(a^(b-1)), if b is odd

#include <iostream>
using namespace std;

int calcPower(int a, int b)
{
    int res;
    if (b == 0)
        return 1;
    if (b == 1)
        return a;

    if (b && 1 == 0) // b is even
    {
        return calcPower(a *  a, b >> 1);
    }
    else
    {
        return a*calcPower(a, b-1);
    }
}
int main()
{
    cout << calcPower(3, 4) << endl;
    return 0;
}