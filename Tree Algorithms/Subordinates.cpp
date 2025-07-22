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

void dfs(int src, vector<vector<int>>& adj, vector<int>& subs, vector<bool>& vis){
    vis[src] = true;
    int cnt = adj[src].size();
    for(int node : adj[src]){
        if(!vis[node])
            dfs(node, adj, subs, vis);
        cnt += subs[node];
    }
    subs[src] = cnt;
}

int main() {
    fastio

    int n;
    cin >> n;

    vector<vector<int>> adj(n + 1, vector<int>());
    for(int i = 2; i <= n; i++){
        int x;
        cin >> x;
        adj[x].push_back(i);
    }

    vector<int> subs(n + 1, 0);
    vector<bool> vis(n + 1, false);

    dfs(1, adj, subs, vis);
    for(int i = 1; i <= n; i++)
        cout << subs[i] << " ";
    return 0;
}