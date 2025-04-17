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

    
    int t;
    cin >> t;

    // precomputing to all test cases
    vector<int> queries(t);
    take(queries, t);
    int n = 1e6;

    // building from bottom to top
    // dp[i][0] -> no.of ways to fill 2 x t grid from ith row to t - 1th row
    // such that top is one 2 x 1 block.|_ _| (TYPE 0 block)
    // dp[i][1] -> no.of ways to fill 2 x t grid from ith row to t - 1th row
    // such that top is two 1 x 1 blocks.|_||_| (TYPE 1 block)
    vector<vector<ll>> dp(n, vector<ll> (2, 0));
    dp[n - 1][0] = 1;
    dp[n - 1][1] = 1;

    loopRev(i, n - 2, 0){
        // if i + 1th row is 0th type,
        // ith row can have
        // if closed, one 0th type or one 1 type
        // if open/continued, one 0 type.

        // dp[i][0] = (dp[i + 1][0] % mod + dp[i + 1][0]
        //              % mod + dp[i + 1][1] % mod) % mod;

        dp[i][0] = (2 * dp[i + 1][0] + dp[i + 1][1]) % mod;

        // if i + 1th row is 1th type,
        // ith row can have
        // if partial close, two type 1
        // if closed, one 0th type or one 1 type
        // if open/continued, one type 1.
        
        // dp[i][1] = (dp[i + 1][1] % mod + dp[i + 1][1] % mod + 
        //             dp[i + 1][1] % mod + dp[i + 1][1] % mod +
        //             dp[i + 1][0] % mod) % mod;
        dp[i][1] = (4 * dp[i + 1][1] + dp[i + 1][0]) % mod;
    }

    for(int q : queries){
        cout << (dp[n - q][0] + dp[n - q][1]) % mod << endl;
    }

    return 0;
}