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

bool isPossible = true;

// BFS APPROACH
// void bfs(queue<int>& q, vector<vector<int>>& adj, vector<int>& team){
//     while(!q.empty()){
//         int node = q.front();
//         q.pop();

//         for(int adjNode : adj[node]){
//             if(team[adjNode] != -1){
//                 if(team[adjNode] == team[node]){
//                     isPossible = false;
//                     return;
//                 }
//                 else continue;
//             }
//             team[adjNode] = 3 - team[node];
//             q.push(adjNode);
//         }
//     }
// }

// DFS APPROACH
void dfs(int node, int t, vector<vector<int>>& adj, vector<int>& team){
    team[node] = t;
    for(int adjNode : adj[node]){
        if(team[adjNode] == -1)
            dfs(adjNode, 3 - t, adj, team);
        else if(team[adjNode] == t){
            isPossible = false;
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

    vector<int> team(n + 1, -1);
    
    // BFS APPROACH
    // loop(i, 1, n + 1){
    //     if(team[i] != -1) continue;
    //     queue<int> q;
    //     q.push(i);
    //     team[i] = 1;
    //     bfs(q, adj, team);
    //     if(!isPossible) break;
    // }

    // DFS APPROACH
    loop(i, 1, n + 1){
        if(team[i] == -1)
            dfs(i, 1, adj, team);
        if(!isPossible) break;
    }

    if(isPossible)
        loop(i, 1, n + 1) cout << team[i] << " ";
    else
        cout << "IMPOSSIBLE";

    return 0;
}