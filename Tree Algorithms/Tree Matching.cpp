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

    void dfs(int u, int par, int take, vector<vector<int>>& G) {
        if(dp[u][take] != -1) return;

        int ans = 0;

        // if we SHOULD take u, we can take u with only one of the many u->v edges.
        if(take) {
            int takeAll = 0;
            // what we can get if we take all u->v edges (even though we shouldn;t take it)
            for(int v : G[u]) {
                if(v == par) continue;

                if(dp[v][1] == -1) dfs(v, u, 1, G);

                takeAll += dp[v][1];
            }

            // from alltaken value, for each node, if that edge is selected, then
            for(int v : G[u]) {
                if(v == par) continue;

                if(dp[v][0] == -1) dfs(v, u, 0, G);

                //from total - (value if v is also taken) - (1 + value if v shouldn't be taken)
                ans = max(ans, takeAll - dp[v][1] + (1 + dp[v][0]));
            }
        }
        else {
            // if u should be taken, all of u neighbours can be taken or not taken (NO SHOULD)
            for(int v : G[u]){
                if(v == par) continue;

                if(dp[v][1] == -1) dfs(v, u, 1, G);
                if(dp[v][0] == -1) dfs(v, u, 0, G);

                ans += max(dp[v][0], dp[v][1]);
            }
        }

        dp[u][take] = ans;
    }
  public:
    void maximumPairs(int n, vector<vector<int>>& G) {
        //dp[i][j] (j = (1 or 2)) -> ith node is taken if j is 1, else ith node is not taken
        dp.resize(n + 1, vector<int>(2, -1));

        // root SHOULD not be taken
        dfs(1, -1, 0, G);
        // root SHOULD be taken
        dfs(1, -1, 1, G);

        cout << max(dp[1][0], dp[1][1]);
    }
};

int main() {
    fastio

    int n;
    cin >> n;

    vector<vector<int>> G(n + 1);
    loop(i, 0, n - 1) {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    Solution sol;
    sol.maximumPairs(n, G);

    return 0;
}