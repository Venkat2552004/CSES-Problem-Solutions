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
    vector<int> subs;

    void dfs(int u, vector<vector<int>>& G) {
        subs[u] = G[u].size();

        for(int v : G[u]) {
            if(subs[v] == -1)
                dfs(v, G);
            subs[u] += subs[v];
        }
    }
  public:
    void getSubordinates(int n, vector<vector<int>>& G) {
        subs.resize(n + 1, -1);

        dfs(1, G);

        loop(i, 1, n + 1) cout << (subs[i] == -1 ? 0 : subs[i]) << " ";
    }
};

int main() {
    fastio

    int n;
    cin >> n;

    vector<vector<int>> G(n + 1);
    loop(i, 2, n + 1) {
        int u;
        cin >> u;
        G[u].push_back(i);
    }

    Solution sol;
    sol.getSubordinates(n, G);

    return 0;
}