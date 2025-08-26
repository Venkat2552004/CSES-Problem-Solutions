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
    vector<int> level;

    void preProcess(int u, int par, vector<vector<int>>& G) {
        dp[0][u] = par;

        loop(i, 1, 21) {
            if(dp[i - 1][u] != 0)
                dp[i][u] = dp[i - 1][dp[i - 1][u]];
            else
                dp[i][u] = 0;
        }

        for(int v : G[u]) {
            if(v == par) continue;
            preProcess(v, u, G);
        }
    }

    void dfs(int u, int par, int lvl, vector<vector<int>>& G) {
        level[u] = lvl;

        for(int v : G[u]) {
            if(v == par) continue;
            dfs(v, u, lvl + 1, G);
        }
    }

   int jumpsToLCA(int u, int v) {
 
        if(u == v) return 0;
 
        int jumps = 0;
        loopRev(i, 20, 0) {
            // 2^i steps, but still not common node, the jump
            if(dp[i][u] != dp[i][v]){
                jumps += (1 << i);
                u = dp[i][u];
                v = dp[i][v];
            }
        }
 
        // after jumps, we still haven't reached LCA, just one step away
        return jumps + 1;
    }
  public:
    void distance(int n, vector<vector<int>>& G, vector<vector<int>>& queries) {
        // dp[i][j] = 2^i th higher up of j
        dp.resize(21, vector<int>(n + 1, 0));
        // lvl[i] = level of node i from root;
        level.resize(n + 1, 0);

        //fills dp array
        preProcess(1, 0, G);

        // fills the level array
        dfs(1, 0, 0, G);

        for(auto query : queries) {
            int u = query[0], v = query[1];

            int d = 0;

            if(level[v] > level[u]) swap(u, v);

            if(level[u] > level[v]){
                int k = level[u] - level[v];
                d += k;
                loop(i, 0, 20) {
                    if(k >> i & 1)
                    u = dp[i][u];
                }
            }

            cout << d + 2 * jumpsToLCA(u, v) << "\n";

        }
    }
};

int main() {
    fastio

    int n, q;
    cin >> n >> q;

    vector<vector<int>> G(n + 1);
    loop(i, 2, n + 1) {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    vector<vector<int>> queries;
    loop(i, 0, q) {
        int x, k;
        cin >> x >> k;
        queries.push_back({x, k});
    }

    Solution sol;
    sol.distance(n, G, queries);

    return 0;
}