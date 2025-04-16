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
#define loopRev(var, start, end) for (int var = start; var >= end; var--)
#define newline cout << endl
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);

const ll mod = 1e9 + 7;

int main() {
    fastio

    int n, sum;
    cin >> n >> sum;

    vector<int> coins(n);
    take(coins, n);

    vector<vector<int>> dp(n + 1, vector<int> (sum + 1, 0));
    loop(i, 0, n + 1) dp[i][0] = 1;

    loopRev(i, n - 1, 0){
        loop(j, 1, sum + 1){
            int skip = dp[i + 1][j];
            int pick = 0;
            if(coins[i] <= j)
                pick = dp[i][j - coins[i]];
            dp[i][j] = (skip + pick) % mod;
        }
    }

    cout << dp[0][sum];
    return 0;
}