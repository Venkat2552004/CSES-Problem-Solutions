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
     
    int n;
    cin >> n;

    ll mw;
    cin >> mw;

    vector<ll> arr(n);
    takeInput(arr, n);
    sort(arr);

    int i = 0, j = n - 1, cnt = 0;
    

    while(i < j){
        if(arr[i] + arr[j] <= mw){
            cnt++;
            i++;
        }
        j--;
    }

    cout << n - cnt;
    return 0;
}