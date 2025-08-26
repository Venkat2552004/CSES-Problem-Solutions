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

    void dfs(int u, vector<int>& G) {
        int v = G[u];
        if(level[v] == -1)
            dfs(v, G);
        level[u] = 1 + level[v];
    }

    int LCA(int u, int v) {
        if(level[v] > level[u]) swap(u, v);
        if(level[u] > level[v]){
            int k = level[u] - level[v];
            // move u to k-levels up;
            loop(i, 0, 31) {
                if(k >> i & 1)
                    u = dp[i][u];
            }
        }
        //cout << u << " " << v << "\n";
        // now u and v are in same level
        // case 1 : after moving to same level, if they are at same node, it is thier LCA;
        if(u == v) return u;

        // using BS to find the LCA;
        // starting from LCA, every level up is same node. We have to find, least jumps to make so that
        // from that mode, every jump from u and v result in same node
        // level[u] == level[v] but u != 1, so low = 1 (atleast 1 jump should be made)
        // high = level[u] (after current level steps, we reach root, no more level jumps is not possible)
        int low = 0, high = level[u]; // or level[v] as both are same
        while(low < high - 1) {
            int mid = low + (high - low) / 2;
            int u_afterJumps = u;
            int v_afterJumps = v;
            loop(i, 0, 31) {
                if(mid >> i & 1){
                    u_afterJumps = dp[i][u_afterJumps];
                    v_afterJumps = dp[i][v_afterJumps];
                }
            }
            if(u_afterJumps == v_afterJumps)
                high = mid;
            else low = mid;
        }
        
        //making (high) jumps from u or v
        int lca = v;
        loop(i, 0, 31) {
            if(high >> i & 1) lca = dp[i][lca];
        }

        return lca;

    }
  public:
    void leastCommonAncestor(int n, vector<int>& G, vector<vector<int>>& queries) {
        // dp[i][j] = 2^i th higher up of j
        dp.resize(20, vector<int>(n + 1, 0));
        // lvl[i] = level of node i from root;
        level.resize(n + 1, -1);

        // dp[i][0] is not needed, so we use it for something else by putting entire column = 0
        // immediate parnet of 1 is set to 0.
        // to stay in limit of any k values, 0 parent is also 0, so any xth level up from 0 is 0 itself
        loop(i, 0, n + 1) dp[0][i] = G[i];
        loop(i, 0, 20) dp[i][0] = 0;

        loop(i, 1, 20) {
            loop(j, 1, n + 1) {
                dp[i][j] = dp[i - 1][dp[i - 1][j]];
            }
        }

        level[1] = 0;
        loop(i, 2, n + 1){
            if(level[i] == -1)
                dfs(i, G);
        }

        for(auto query : queries) {
            int x = query[0], y = query[1];
            cout << LCA(x, y) << "\n";
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
    sol.leastCommonAncestor(n, G, queries);

    return 0;
}