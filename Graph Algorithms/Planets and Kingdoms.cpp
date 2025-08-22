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
    vector<int> ans;
    void dfs(int u, vector<int>& vis, stack<int>& st, vector<vector<int>>& G, int type, int k) {
        vis[u] = 1;

        for(int v : G[u])
            if(!vis[v])
                dfs(v, vis, st, G, type, k);

        if(type == 1) st.push(u);
        if(type == 2) ans[u] = k;
    }
  public:
    void assignKingdom(int n, vector<vector<int>>& G) {
        vector<int> vis(n + 1);
        stack<int> st;

        loop(i, 1, n + 1)
            if(!vis[i])
                dfs(i, vis, st, G, 1, -1);
        
        vector<vector<int>> R(n + 1);
        loop(u, 1, n + 1)
            for(int v : G[u])
                R[v].push_back(u);
        
        int k = 1;
        loop(i, 1, n + 1) vis[i] = 0;
        ans.resize(n + 1);

        while(!st.empty()) {
            int u = st.top();
            st.pop();

            if(vis[u]) continue;
            dfs(u, vis, st, R, 2, k);
            k++;
        }

        cout << k - 1 << endl;
        loop(i, 1, n + 1) cout << ans[i] << " ";

        return;
    }
};

int main() {
    fastio

    int n, m;
    cin >> n >> m;

    vector<vector<int>> G(n + 1);
    loop(i, 0, m) {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
    }

    Solution sol;
    sol.assignKingdom(n, G);    

    return 0;
}