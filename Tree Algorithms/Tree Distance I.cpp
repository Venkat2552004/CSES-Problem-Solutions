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
    vector<int> bfs(int src, int n, vector<vector<int>>& G) {
        vector<int> dist(n + 1, -1);
        queue<int> q;

        q.push(src);

        int d = 0;
        while(!q.empty()) {
            int sz = q.size();
            while(sz--) {
                int u = q.front();
                q.pop();
    
                if(dist[u] != -1) continue;
                dist[u] = d;

                for(int v : G[u])
                    if(dist[v] == -1) q.push(v);
            }
            d++;
        }
        return dist;
    }
  public:
    void maximumDistance(int n, vector<vector<int>>& G) {
        vector<int> distFromRoot = bfs(1, n, G);
        int diameterEnd1 = 1;
        loop(i, 2, n + 1) if(distFromRoot[i] > distFromRoot[diameterEnd1]) diameterEnd1 = i;
        vector<int> distFromDiameterEnd1 = bfs(diameterEnd1, n, G);
        int diameterEnd2 = 1;
        loop(i, 2, n + 1) if(distFromDiameterEnd1[i] > distFromDiameterEnd1[diameterEnd2]) diameterEnd2 = i;
        vector<int> distFromDiameterEnd2 = bfs(diameterEnd2, n, G);

        loop(i, 1, n + 1)
            cout << max(distFromDiameterEnd1[i], distFromDiameterEnd2[i]) << " ";
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
    sol.maximumDistance(n, G);

    return 0;
}