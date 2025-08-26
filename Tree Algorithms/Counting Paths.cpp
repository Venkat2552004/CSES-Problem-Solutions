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
    vector<vector<int>> ancestor;
    vector<int> level;
    vector<int> ans;

    void dfs1(int u, int par, int lvl, vector<vector<int>>& G) {
        level[u] = lvl;
        ancestor[u][0] = par;

        loop(i, 1, 20) {
            ancestor[u][i] = ancestor[ancestor[u][i - 1]][i - 1];
        }

        for(int v : G[u]) {
            if(v == par) continue;
            dfs1(v, u, lvl + 1, G);
        }
    }

    int LCA(int u, int v) {
        if(level[v] > level[u]) swap(u, v);

        int k = level[u] - level[v];

        loop(i, 0, 20) {
            if(k >> i & 1)
                u = ancestor[u][i];
        }

        if(u == v) return u;

        loopRev(i, 19, 0) {
            if(ancestor[u][i] != ancestor[v][i]){
                u = ancestor[u][i];
                v = ancestor[v][i];
            }
        }

        return ancestor[u][0];
    }

    void dfs2(int u, int par, vector<vector<int>>& G) {
        for(int v : G[u]) {
            if(v == par) continue;
            dfs2(v, u, G);
            ans[u] += ans[v];
        }
    }

  public:
    void countingPaths(int n, vector<vector<int>>& paths, vector<vector<int>>& G) {
        ancestor.resize(n + 1, vector<int>(20, 0));
        level.resize(n + 1, 0);
        ans.resize(n + 1, 0);
        
        dfs1(1, 0, 0, G);

        for(auto path : paths) {
            int u = path[0];
            int v = path[1];

            int lca = LCA(u, v);
            int lca_par = ancestor[lca][0];

            ans[u]++, ans[v]++;
            ans[lca]--, ans[lca_par]--;
        }

        dfs2(1, 0, G);

        loop(i, 1, n + 1) cout << ans[i] << " ";
    }
};

int main() {
    fastio

    int n, m;
    cin >> n >> m;

    vector<vector<int>> G(n + 1);
    loop(i, 0, n - 1) {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    vector<vector<int>> paths;
    loop(i, 0, m) {
        int a, b;
        cin >> a >> b;
        paths.push_back({a, b});
    }

    Solution sol;
    sol.countingPaths(n, paths, G);

    return 0;
}