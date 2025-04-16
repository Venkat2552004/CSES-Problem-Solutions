#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ul unsigned long
#define ull unsigned long long
#define takeInput(arr, n) for(int i = 0; i < n; i++) cin >> arr[i];
#define sort(arr) sort(arr.begin(), arr.end())
#define print(arr) for(auto i : arr) cout << i << ' ';

ll mod = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    
    multiset<ll> ms;
    while(n--){
        ll x;
        cin >> x;
        ms.insert(x);
    }

    while(m--){
        ll price;
        cin >> price;
        ll ans = -1;
        auto it = ms.upper_bound(price);
        if(it != ms.begin()){
            it--;
            ans = *it;
            ms.erase(it);
        }
        cout << ans << endl;
    }
    return 0;
}