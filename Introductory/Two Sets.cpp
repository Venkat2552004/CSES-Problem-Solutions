#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ul unsigned long
#define ull unsigned long long
#define mod 1000000007
#define takeInput(arr, n) for(int i = 0; i < n; i++) cin >> arr[i];

void solve(ull n, ull sum){
    ll target = sum / 2;
    int cnt = 0;
    vector<bool> vis(n + 1);
    ll i = n;
    
    while(i > 0 && target != 0){
        if(target - i >= 0){
            vis[i] = 1;
            target -= i;
            cnt++;
        }
        i--;
    }

    cout << "YES" << endl << cnt << endl;
    for(int i = 1; i <= n; i++)
        if(vis[i]) cout << i << " ";
        
    cout << endl << n - cnt << endl;
    for(int i = 1; i <= n; i++)
        if(!vis[i]) cout << i << " ";
}

int main() {
    ull n;
    cin >> n;

    ull sum = n * (n + 1) / 2;
    if(sum & 1)
        cout << "NO";
    else
        solve(n, sum);
    return 0;
}