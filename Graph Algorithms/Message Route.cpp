#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ul unsigned long
#define ull unsigned long long
#define take(A, N) for(int idx = 0; idx < N; idx++) cin >> A[idx];
#define print(A) for(auto element : A) cout << element << ' ';
#define println(A) for(auto element : A) cout << element << endl;
#define sort(A) sort(A.begin(), A.end())
#define sum(A) accumulate(A.begin(), A.end(), 0)
#define all(A) A.begin(), A.end()
#define loop(var, start, end) for(int var = start; var < end; var++)
#define newline cout << endl
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);

ll mod = 1e9 + 7;

int main() {
    fastio

    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n + 1);
    loop(i, 0, m){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> par(n + 1, -1);
    vector<int> dist(n + 1, INT_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    
    pq.push({0, 1});
    dist[1] = 0;
    
    while(!pq.empty()){
        auto [d, node] = pq.top();
        pq.pop();

        for(int adjNode : adj[node]){
            if(dist[adjNode] > dist[node] + 1){
                par[adjNode] = node;
                dist[adjNode] = dist[node] + 1;
                pq.push({dist[adjNode], adjNode});
            }
        }
    }

    if(dist[n] == INT_MAX)
        cout << "IMPOSSIBLE";
    else{
        vector<int> path;
        int node = n;
        while(node != -1){
            path.push_back(node);
            node = par[node];
        }

        reverse(all(path));
        cout << path.size() << endl;
        for(int node : path) cout << node << " ";
    }


    return 0;
}