#include <iostream>
using namespace std;
#define ull unsigned long long

int main()
{
    ull n;
    cin >> n;
    while (n > 0)
    {
        cout << n << " ";
        if (n == 1)
            break;
        if (n & 1)
            n = (n * 3) + 1;
        else
            n /= 2;
    }
    return 0;
}