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

    int dfs(int u, int par, vector<vector<int>>& G) {
        int child = 0;
        for(int v : G[u]) {
            if(v == par) continue;
            int hv = 1 + dfs(v, u, G);

            if(hv > dp[u][0]){
                dp[u][1] = dp[u][0];
                dp[u][0] = hv;
            }
            else if(hv > dp[u][1])
                dp[u][1] = hv;

            child++;
        }

        if(child == 0) return 0;
        return dp[u][0];
    }
  public:
    int diameter(int n, vector<vector<int>>& G) {
        // dp[u][0], dp[u][1] -> max 2 heights of all subtrees of u (including u).
        dp.resize(n + 1, vector<int>(2, 0));

        // need par because the edges are undirected
        dfs(1, -1, G);

        int ans = 0;
        loop(i, 1, n + 1) {
            ans = max(ans, dp[i][0] + dp[i][1]);
        }
        return ans;
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
    cout << sol.diameter(n, G);

    return 0;
}