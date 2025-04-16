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

void dfs(int node, vector<bool>& vis, vector<vector<int>>& adj){
    if(vis[node]) return;
    vis[node] = true;
    for(int adjNode : adj[node])
        dfs(adjNode, vis, adj);
}

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

    vector<int> mainRoads;
    vector<bool> vis(n + 1, false);

    loop(i, 1, n + 1){
        if(!vis[i]){
            mainRoads.push_back(i);
            dfs(i, vis, adj);
        }
    }


    if(mainRoads.size() == 1)
        cout << "0";
    else{
        int N = mainRoads.size();
        cout << N - 1 << endl;
        loop(i, 0, N - 1)
            cout << mainRoads[i] << " " << mainRoads[i + 1] << endl;
    }
    return 0;
}