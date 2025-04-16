#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ul unsigned long
#define ull unsigned long long
#define takeInput(arr, n) for(int i = 0; i < n; i++) cin >> arr[i];
#define sort(arr) sort(arr.begin(), arr.end())

ll mod = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll n, m, k;
    cin >> n >> m >> k;

    vector<ll> arr(n), app(m);
    takeInput(arr, n);
    takeInput(app, m);

    sort(arr);
    sort(app);

    int cnt = 0;

    int i = 0, j = 0;
    while(i < n && j < m){
        if(abs(arr[i] - app[j]) <= k){
            cnt++;
            i++, j++;
        }
        else if(arr[i] < app[j]) i++;
        else j++;
    }
    cout << cnt;
    return 0;
}