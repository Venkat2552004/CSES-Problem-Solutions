#include <iostream>
using namespace std;

#define ll long long
#define ul unsigned long
#define ull unsigned long long
#define mod 1000000007

int main() {
    int n;
    cin >> n;
    int ans = 0;

    for(int i = 1; i <= n; i++)
        ans ^= i;

    for(int i = 1; i < n; i++){
        int x;
        cin >> x;
        ans ^= x;
    }

    cout << ans;
    return 0;
}