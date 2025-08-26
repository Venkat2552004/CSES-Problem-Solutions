#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ul unsigned long
#define ull unsigned long long
#define take(A, N) for(int idx = 0; idx < N; idx++) cin >> A[idx]
#define print(A) for(auto element : A) cout << element << ' '
#define println(A) for(auto element : A) cout << element << endl
#define sum(A) accumulate(A.begin(), A.end(), 0)
#define all(A) A.begin(), A.end()
#define loop(var, start, end) for(int var = start; var < end; var++)
#define loopRev(var, start, end) for(int var = start; var >= end; var--)
#define newline cout << "\n"
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);

const ll mod = 1e9 + 7;

class Solution {
  private:
    vector<vector<int>> dp;
  public:
    void kthHigherUp(int n, int q, vector<int>& G, vector<vector<int>>& queries) {
        // dp[i][j] = 2^i th higher up of j
        dp.resize(20, vector<int>(n + 1, 0));

        // dp[i][0] is not needed, so we use it for something else by putting entire column = 0
        // immediate higher-up of 1 is set to 0, while printing, 0 means no higher-up, so print -1;
        // to stay in limit of any k values, 0 higher up is 0, so any x higher up of 0 is 0 itself
        loop(i, 0, n + 1) dp[0][i] = G[i];
        loop(i, 0, 20) dp[i][0] = 0;

        loop(i, 1, 20) {
            loop(j, 1, n + 1) {
                dp[i][j] = dp[i - 1][dp[i - 1][j]];
            }
        }

        for(auto query : queries) {
            int x = query[0], k = query[1];
            int curr = x;
            for(int i = 0; i < 30; i++) {
                if(k >> i & 1) curr = dp[i][curr];
            }
            cout << (curr == 0 ? -1 : curr);
            newline;
        }
    }
};

int main() {
    fastio

    int n, q;
    cin >> n >> q;

    vector<int> G(n + 1, 0);
    loop(i, 2, n + 1) cin >> G[i];

    vector<vector<int>> queries;
    loop(i, 0, q) {
        int x, k;
        cin >> x >> k;
        queries.push_back({x, k});
    }

    Solution sol;
    sol.kthHigherUp(n, q, G, queries);

    return 0;
}