#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ul unsigned long
#define ull unsigned long long
#define takeInput(arr, n) for(int i = 0; i < n; i++) cin >> arr[i];

ll mod = 1e9 + 7;

int main() {
    int t;
    cin >> t;
    while(t--){
        ll a, b;
        cin >> a >> b;

        ll mx = max(a, b);
        ll mn = min(a, b);

        if((a + b) % 3 == 0 && mx <= 2 * mn)
            cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}