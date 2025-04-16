#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ul unsigned long
#define ull unsigned long long
#define takeInput(arr, n) for(int i = 0; i < n; i++) cin >> arr[i];

long long mod = 1e9 + 7;

ll calPow(ll n,  ll x){
    ll ans = 1LL, po = n % mod;
    while(x > 0){
        if(x & 1) ans = ans * po % mod;
        po = po * po % mod;
        x >>= 1;
    }
    return ans;
}

int main() {
    ll n;
    cin >> n;
    
    cout << calPow(2, n);
    return 0;
}