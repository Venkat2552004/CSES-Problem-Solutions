#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ul unsigned long
#define ull unsigned long long
#define take(A, N) for(int idx = 0; idx < N; idx++) cin >> A[idx]
#define print(A) for(auto element : A) cout << element << ' '
#define println(A) for(auto element : A) cout << element << endl
#define sum(A) accumulate(A.begin(), A.end(), 0)
#define all(A) A.begin(), A.end()
#define loop(var, start, end) for(int var = start; var < end; var++)
#define loopRev(var, start, end) for(int var = start; var >= end; var--)
#define newline cout << "\n"
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);

const ll mod = 1e9 + 7;

class Solution {
  private:
    vector<ll> dist, size;

    // calculate size of each node, also update dist array of node partially
    // after this function, dist[i] = sum of distance of i to all nodes in its subtree
    // since 1 is root, dist[1] -> will have its final answer
    void dfs1(int u, int par, vector<vector<int>>& G) {
        for(int v : G[u]) {
            if(v == par) continue;
            dfs1(v, u, G);
            // since u is parent of v
            size[u] += size[v];
            // dist[v] has sum total to reach all nodes in its subtree
            // so from u to v, 1 edge need to be travelled to visit each node.
            // for size[v] nodes, 1 * (size[v]) = size[v]
            dist[u] += dist[v] + size[v];
        }
    }

    // now root has its correct value, use it to update immediate child, and apply same for thier children
    void dfs2(int u, int par, int n, vector<vector<int>>& G) {
        for(int v : G[u]) {
            if(v == par) continue;
            // rem no.of nodes v has to visit
            ll remainingNodes = n - size[v];
            // v parent has sum distance to every node
            ll rem_nodes_dist_from_parent = dist[u] - dist[v] - size[v];
            // to calc dist for each node, i have to travel to my parent first for each of that node
            dist[v] += rem_nodes_dist_from_parent + remainingNodes;
            dfs2(v, u, n, G);
        }
    }
  public:
    void sumOfDistances(int n, vector<vector<int>>& G) {
        // dist[i] = sum of distance to every other node
        dist.resize(n + 1, 0);
        // size[i] = size of the subtree whose root is i including itself
        size.resize(n + 1, 1);
    
        dfs1(1, -1, G);
        dfs2(1, -1, n, G);

        loop(i, 1, n + 1) cout << dist[i] << " ";
    }
};

int main() {
    fastio

    int n;
    cin >> n;

    vector<vector<int>> G(n + 1);
    loop(i, 0, n - 1) {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    Solution sol;
    sol.sumOfDistances(n, G);

    return 0;
}