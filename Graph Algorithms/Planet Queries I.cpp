#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ul unsigned long
#define ull unsigned long long
#define take(A, N) for(int idx = 0; idx < N; idx++) cin >> A[idx];
#define print(A) for(auto element : A) cout << element << ' ';
#define println(A) for(auto element : A) cout << element << endl;
#define sum(A) accumulate(A.begin(), A.end(), 0)
#define all(A) A.begin(), A.end()
#define loop(var, start, end) for(int var = start; var < end; var++)
#define loopRev(var, start, end) for(int var = start; var >= end; var--)
#define newline cout << endl
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);

const ll mod = 1e9 + 7;

class Solution {
  private:
    
  public:
    void finalStop(int n, vector<int>& G, vector<vector<int>>& queries) {
        // Binary lifting
        // 2^10 ~ 10^3 -> 10^9 ~ 2^30
        // we need 31 bits to represent 10^9
        // dp[i][j] = final planet of j after 2^i teleportations
        // 2^i = (2^(i - 1) + 2^(i - 1)) [ 2.2^(i - 1) = 2^(i - 1 + 1) = 2^i]
        // take 2^(i - 1) from j -> reached some k, then again take 2^(i - 1) steps from k.
        // result is 2^i steps from j;
        vector<vector<int>> dp(31, vector<int> (n + 1));

        loop(i, 1, n + 1) dp[0][i] = G[i];
        
        loop(i, 1, 31) {
            loop(j, 1, n + 1) {
                int afterHalfSteps = dp[i - 1][j];
                dp[i][j] = dp[i - 1][afterHalfSteps];
            }
        }

        for(auto query : queries) {
            int u = query[0], k = query[1];
            int curr = u;
            loop(i, 0, 31){
                if(k >> i & 1){
                    curr = dp[i][curr];
                }
            }
            cout << curr << endl;
        }

    }
};

int main() {
    fastio

    int n, m;
    cin >> n >> m;

    vector<int> G(n + 1);
    loop(i, 1, n + 1) cin >> G[i];

    vector<vector<int>> queries;
    loop(i, 0, m) {
        int u, k;
        cin >> u >> k;
        queries.push_back({u, k});
    }

    Solution sol;
    sol.finalStop(n, G, queries);

    return 0;
}