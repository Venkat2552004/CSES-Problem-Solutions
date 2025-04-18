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
#define loopRev(var, start, end) for(int var = start; var >= end; var--)
#define newline cout << endl
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);

const ll mod = 1e9 + 7;

int main() {
    fastio

    int n;
    cin >> n;

    vector<int> coins(n);
    take(coins, n);

    int maxSum = accumulate(all(coins), 0);
    
    // dp[i][j] --> is it possible to make sum j using 1st i coins
    // 1 -> Yes, 0 -> No
    vector<vector<int>> dp(n, vector<int>(maxSum + 1, 0));
    dp[0][coins[0]] = 1;
    loop(i, 0, n) dp[i][0] = 1;


    loop(i, 1, n){
        loop(j, 1, maxSum + 1){
            // if current coins can't be used, can we make sum j using only previous coins
            if(coins[i] > j)
                dp[i][j] = dp[i - 1][j];
            // if current coin can be used, is it possible to make sum j using / not using current coin
            else
                dp[i][j] = (dp[i - 1][j - coins[i]] == 1) | dp[i - 1][j];
        }
    }

    // dp[i][0] = 1, we dont count 0 as a sum value;
    int ans = accumulate(all(dp[n - 1]), -1);

    cout << ans << endl;
    loop(j, 1, maxSum + 1)
        if(dp[n - 1][j] == 1)
            cout << j << " ";

    return 0;
}