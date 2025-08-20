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
    vector<ll> dijkstras(int src, vector<vector<pair<int, int>>>& G) {
        int n = G.size() - 1;
        vector<bool> vis(n + 1);
        vector<ll> dist(n + 1, LLONG_MAX);
        priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
      
        pq.push({0, src});
        dist[src] = 0;
        
        while(!pq.empty()) {
            auto [w, node] = pq.top();
            pq.pop();
      
            if(vis[node]) continue;
            vis[node] = true;
            for(auto [adjNode, cost] : G[node]){
                if(!vis[adjNode] && (w + cost < dist[adjNode])){
                    dist[adjNode] = w + cost;
                    pq.push({w + cost, adjNode});
                }
            }
        }
        return dist;
    }
  public:
    ll minimumCost(int n, vector<vector<pair<int, int>>>& G, vector<vector<pair<int, int>>>& R) {

        vector<ll> distFrom1 = dijkstras(1, G);
        vector<ll> distFromN = dijkstras(n, R);

        ll ans = LLONG_MAX;
        
        loop(u, 1, n + 1) {
            if(distFrom1[u] == LLONG_MAX) continue;
            for(auto [v, w] : G[u]){
                if(distFromN[v] == LLONG_MAX) continue;
                ans = min(ans, distFrom1[u] + w / 2 + distFromN[v]);
            }
        }

        return ans;
    }

};

int main() {
    fastio

    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> G(n + 1);
    vector<vector<pair<int, int>>> R(n + 1);
    loop(i, 0, m){
        int u, v, w;
        cin >> u >> v >> w;
        G[u].push_back({v, w});
        R[v].push_back({u, w});
    }

    Solution sol;
    cout << sol.minimumCost(n, G, R);

    return 0;
}