#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ul unsigned long
#define ull unsigned long long
#define takeInput(arr, n) for(int i = 0; i < n; i++) cin >> arr[i];

ll mod = 1e9 + 7;

int main() {
    ll n;
    cin >> n;

    ll ans = 0, p = 5;
    while(p <= n){
        ans += n / p;
        p *= 5;
    }
    cout << ans;
    return 0;
}