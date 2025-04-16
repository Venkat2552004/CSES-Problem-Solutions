#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ul unsigned long
#define ull unsigned long long
#define take(A, N) for(int idx = 0; idx < N; idx++) cin >> A[idx];
#define print(A) for(auto element : A) cout << element << ' ';
#define println(A) for(auto element : A) cout << element << endl;
#define sort(A) sort(A.begin(), A.end())
#define sum(A) accumulate(A.begin(), A.end(), 0)
#define all(A) A.begin(), A.end()
#define loop(var, start, end) for(int var = start; var < end; var++)
#define newline cout << endl
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);

ll mod = 1e9 + 7;

int main() {
    fastio

    int n, sum;
    cin >> n >> sum;

    vector<int> coins(n);
    loop(i, 0, n) cin >> coins[i];
    sort(coins);

    vector<int> dp(sum + 1, INT_MAX);
    dp[0] = 0;

    loop(i, 1, sum + 1){
        loop(j, 0, n){
            if(i >= coins[j] && dp[i - coins[j]] != INT_MAX) 
                dp[i] = min(dp[i], 1 + dp[i - coins[j]]);
            else if(i < coins[j]) break;
        }
    }

    if(dp[sum] == INT_MAX) cout << -1;
    else cout << dp[sum];
    
    return 0;
}