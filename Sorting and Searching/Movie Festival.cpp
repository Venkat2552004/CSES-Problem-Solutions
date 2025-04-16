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

    vector<pair<int, int>> A;
    for(int i = 0; i < n; i++){
        int x, y;
        cin >> x >> y;
        A.push_back({y - 1, x});
    }

    sort(A);
    int ans = 0, i = 0, taken = 0;
    while(i < n){
        if(A[i].second > taken){
            ans++;
            taken = max(taken, A[i].first);
        }
        i++;
    }
    cout << ans;
    return 0;
}