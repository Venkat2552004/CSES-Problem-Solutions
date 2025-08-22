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
    void dfs(int u, vector<int>& vis, vector<vector<int>>& G) {
        vis[u] = 1;
 
        for(int v : G[u])
            if(!vis[v])
                dfs(v, vis, G);
 
    }
  public:
    void checkRoutes(int n, vector<vector<int>>& G) {
        vector<int> vis(n + 1);
 
        dfs(1, vis, G);
        loop(u, 2, n + 1){
            if(!vis[u]){
                cout << "NO\n";
                cout << 1 << " " << u;
                return;
            }
        }
        
        vector<vector<int>> R(n + 1);
        loop(u, 1, n + 1)
            for(int v : G[u])
                R[v].push_back(u);
        
        loop(i, 1, n + 1) vis[i] = 0;
        
        dfs(1, vis, R);
        loop(u, 2, n + 1){
            if(!vis[u]){
                cout << "NO\n";
                cout << u << " " << 1;
                return;
            }
        }
        
        cout << "YES";
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
    sol.checkRoutes(n, G);    
 
    return 0;
}