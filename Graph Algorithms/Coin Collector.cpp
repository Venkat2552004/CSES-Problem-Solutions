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
    vector<bool> vis;
    vector<int> comp;
    vector<ll> comp_value;
    stack<int> order;

    void dfs1(int u, vector<vector<int>>& G) {
        vis[u] = true;
        for(int v : G[u]) if(!vis[v]) dfs1(v, G);
        order.push(u);
    }

    void dfs2(int u, int id, vector<int>& coins, vector<vector<int>>& G) {
        comp[u] = id;
        comp_value[id] += coins[u];

        for(int v : G[u]) if(comp[v] == -1) dfs2(v, id, coins, G);
    }

    vector<int> topoSort(int n, vector<vector<int>> G) {
        vector<int> ind(n);

        loop(u, 1, n) {
            for(int v : G[u]) ind[v]++;
        }

        queue<int> q;
        loop(i, 1, n) if(ind[i] == 0) q.push(i);

        vector<int> arr;
        arr.push_back(-1); // making it 1 indexed

        while(!q.empty()) {
            int u = q.front();
            q.pop();

            arr.push_back(u);
            for(int v : G[u]){
                ind[v]--;
                if(ind[v] == 0) q.push(v);
            }
        }

        return arr;
    }

  public:
    ll maximumCoins(int n, vector<int>& coins, vector<vector<int>>& G) {
        vis.resize(n + 1);
        comp.resize(n + 1, -1);
        comp_value.resize(n + 1, 0);

        loop(i, 1, n + 1) {
            if(!vis[i]) dfs1(i, G);
        }

        vector<vector<int>> R(n + 1);
        loop(u, 1, n + 1) {
            for(int v : G[u])
                R[v].push_back(u);
        }

        int id = 1;
        while(!order.empty()) {
            int u = order.top();
            order.pop();

            if(comp[u] != -1) continue;
            dfs2(u, id, coins, R);
            id++;
        }

        // print(comp);
        // newline;
        // print(comp_value);
        // newline;

        vector<vector<int>> condensed_G(id);
        loop(u, 1, n + 1) {
            for(int v : G[u]){
                if(comp[u] != comp[v]){
                    condensed_G[comp[u]].push_back(comp[v]);
                }
            }
        }

        vector<int> topoOrder = topoSort(id, condensed_G);
        vector<ll> dp(id, 0);

        // print(topoOrder);
        // newline;
        // loop(i, 1, id){
        //     print(condensed_G[i]);
        //     newline;
        // }

        loop(i, 1, id) {
            int u = topoOrder[i];
            dp[u] += comp_value[u];

            for(int v : condensed_G[u]){
                dp[v] = max(dp[v], dp[u]);
            }
        }

        // print(dp);
        // newline;
        
        return *max_element(dp.begin(), dp.end());
    }
};

int main() {
    fastio

    int n, m;
    cin >> n >> m;

    vector<int> coins(n + 1, 0);
    loop(i, 1, n + 1) cin >> coins[i];

    vector<vector<int>> G(n + 1);
    loop(i, 0, m) {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
    }

    Solution sol;
    cout << sol.maximumCoins(n, coins, G);

    return 0;
}