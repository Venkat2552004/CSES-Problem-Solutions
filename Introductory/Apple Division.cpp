#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ul unsigned long
#define ull unsigned long long
#define takeInput(arr, n) for(int i = 0; i < n; i++) cin >> arr[i];
#define sort(arr) sort(arr.begin(), arr.end())
#define sum(arr, n) accumulate(arr.begin(), arr.end(), n)
#define print(arr) for(auto i : arr) cout << i << ' ';

ll mod = 1e9 + 7;

ll minDiff(vector<int>& arr, int n, ll sum){
    ll s = 0, ans = INT_MAX;

    for(int i = 0; i < (1 << n) - 1; i++) {
        ll s = 0;
        for(int j = 0; j < n; j++){
            if((i >> j) & 1){
                s += arr[j];
            }
        }
        ll diff = abs(sum - 2 * s);
        ans = min(ans, diff);
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> arr(n);
    takeInput(arr, n);

    ll sum = sum(arr, 0LL);
    cout << minDiff(arr, n, sum);
    return 0;
}