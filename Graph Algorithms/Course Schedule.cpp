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
    
  public:
    vector<int> topoSort(int n, vector<vector<int>>& G) {
        vector<int> ind(n + 1);

        loop(u, 1, n + 1)
            for(int v : G[u])
                ind[v]++;

        vector<int> ans;
        queue<int> q;
        loop(i, 1, n + 1) if(ind[i] == 0) q.push(i);

        while(!q.empty()){
            int node = q.front();
            q.pop();

            ans.push_back(node);

            for(int child : G[node]) {
                ind[child]--;
                if(ind[child] == 0) q.push(child);
            }
        }

        loop(i, 1, n + 1) if(ind[i]) return {};
        return ans;
    }
};

int main() {
    fastio

    int n, m;
    cin >> n >> m;

    vector<vector<int>> G(n + 1);
    loop(i, 0, m) {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
    }

    Solution sol;
    vector<int> ans = sol.topoSort(n, G);
    if(ans.size() == 0)
        cout << "IMPOSSIBLE";
    else print(ans);
    

    return 0;
}