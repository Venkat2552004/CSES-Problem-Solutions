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

int main() {
    fastio

    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, ll>>> G(n + 1);
    loop(i, 0, m){
        int u, v, w;
        cin >> u >> v >> w;
        G[u].push_back({v, w});
    }

    vector<bool> vis(n + 1);
    vector<ll> dist(n + 1, LLONG_MAX);
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;

    dist[1] = 0;
    pq.push({0, 1});

    while(!pq.empty()) {
        auto [w, node] = pq.top();
        pq.pop();

        if(vis[node]) continue;
        vis[node] = true;
        for(auto &[adjNode, cost] : G[node]){
            if(w + cost < dist[adjNode]){
                dist[adjNode] = w + cost;
                pq.push({dist[adjNode], adjNode});
            }
        }
    }

    for(int i = 1; i <= n; i++) cout << dist[i] << " ";

    return 0;
}