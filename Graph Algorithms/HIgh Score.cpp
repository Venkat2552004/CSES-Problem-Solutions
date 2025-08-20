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

struct edge {
    int u, v, w;
};

class Solution {
  private:
    
  public:
    void bfs(int src, vector<bool>& vis, vector<vector<int>>& G) {
        queue<int> q;
        q.push(src);

        while(!q.empty()) {
            int node = q.front();
            q.pop();

            if(vis[node]) continue;
            vis[node] = true;
            for(int adjNode : G[node]) {
                if(!vis[adjNode])
                    q.push(adjNode);
            }
        }
    }

    ll maximumScore(vector<edge>& E, vector<vector<int>>& G, vector<vector<int>>& R) {
        int n = G.size() - 1;
        
        vector<bool> visFrom1(n + 1, false);
        vector<bool> visFromN(n + 1, false);

        bfs(1, visFrom1, G);
        bfs(n, visFromN, R);

        vector<ll> dist(n + 1, LLONG_MIN);
        dist[1] = 0;

        loop(k, 0, n - 1){
            for(auto [u, v, w] : E){
                if(dist[u] == LLONG_MIN) continue;
                if(dist[u] + w > dist[v])
                    dist[v] = dist[u] + w;
            }
        }
        
        for(auto [u, v, w] : E){
            if(dist[u] == LLONG_MIN) continue;
            if(dist[u] + w > dist[v]){
                if(visFrom1[v] && visFromN[v]) return -1LL;
                 dist[v] = dist[u] + w;
            }
        }
        
        return dist[n];
    }
};



int main() {
    fastio

    int n, m;
    cin >> n >> m;

    
    vector<vector<int>> G(n + 1);
    vector<vector<int>> R(n + 1);
    vector<edge> E(m);
    loop(i, 0, m){
        int u, v, w;
        cin >> u >> v >> w;
        E[i].u = u, E[i].v = v, E[i].w = w;
        G[u].push_back(v);
        R[v].push_back(u);
    }

    Solution sol;
    cout << sol.maximumScore(E, G, R);

    return 0;
}