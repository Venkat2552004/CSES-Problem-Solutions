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
    vector<int> comp;
    vector<bool> vis, ans;

    void dfs1(int u, stack<int>& st, vector<vector<int>>& G) {
        vis[u] = true;

        for(int v : G[u]) {
            if(!vis[v]) dfs1(v, st, G);
        }

        st.push(u);
    }

    void dfs2(int u, int id, vector<vector<int>>& G) {
        comp[u] = id;

        for(int v : G[u]) {
            if(comp[v] == -1) dfs2(v, id, G);
        }
    }
  public:
    void satisfyAll(int n, int m, vector<vector<int>>& G) {
        int N = 2 * m + 1;

        ans.resize(m + 1);
        comp.resize(N, -1);
        vis.resize(N);

        stack<int> st;
        loop(i, 1, N) {
            if(!vis[i]) dfs1(i, st, G);
        }

        vector<vector<int>> R(N);
        loop(u, 1, N) {
            for(int v : G[u])
                R[v].push_back(u);
        }

        int id = 1;
        while(!st.empty()){
            int u = st.top();
            st.pop();

            if(comp[u] != -1) continue;

            dfs2(u, id, R);
            id++;
        }

        loop(u, 1, m + 1) {
            int neg_u = u + m;
            if(comp[u] == comp[neg_u]){
                cout << "IMPOSSIBLE";
                return;
            }
            if(comp[neg_u] < comp[u]) ans[u] = true;
        }
        
        loop(i, 1, m + 1) {
            if(ans[i]) cout << "+ ";
            else cout << "- ";
        }
    }
};

int main() {
    fastio

    int n, m;
    cin >> n >> m;

    int N = 2 * m + 1;
    vector<vector<int>> G(N);
    
    //building implication graph;
    loop(i, 0, n) {
        char sign1, sign2;
        int u, v;
        cin >> sign1 >> u >> sign2 >> v;        

        if(sign1 == '-') u = u + m;
        if(sign2 == '-') v = v + m;

        int neg_u = (u <= m ? u + m : u - m);
        int neg_v = (v <= m ? v + m : v - m);

        G[neg_u].push_back(v);
        G[neg_v].push_back(u);
    }

    Solution sol;
    sol.satisfyAll(n, m, G);

    return 0;
}