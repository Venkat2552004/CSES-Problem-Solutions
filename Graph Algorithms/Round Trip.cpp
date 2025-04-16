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

bool found = false;
int st = -1;

void dfs(int node, int p, vector<int>& par, vector<vector<int>>& adj, vector<bool>& vis){
    vis[node] = true;
    par[node] = p;

    for(int adjNode : adj[node]){
        if(!vis[adjNode]){
            dfs(adjNode, node, par, adj, vis);
            if(found) return;
        }
        else if(adjNode != p){
            found = true;
            st = adjNode;
            par[adjNode] = node;
            return;
        }
    }
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

    vector<bool> vis(n + 1, false);
    vector<int> par(n + 1, -1);

    loop(i, 1, n + 1){
        if(!vis[i])
            dfs(i, -1, par, adj, vis);
        if(found) break;
    }

    if(found){
        vector<int> cycle;
        int node = par[st];
        cycle.push_back(st);
        while(node != st){
            cycle.push_back(node);
            node = par[node];
        }
        cycle.push_back(st);

        cout << cycle.size() << endl;
        for(int node : cycle) cout << node << " ";
    }
    else
        cout << "IMPOSSIBLE";
    return 0;
}