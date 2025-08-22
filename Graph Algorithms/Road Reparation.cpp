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

struct edge {
    int u, v, w;
};

class Solution {
  private:
    vector<int> par;
    vector<int> rank;

    void build(int n) {
        par.resize(n + 1);
        loop(i, 1, n + 1) par[i] = i;

        rank.resize(n + 1);
    }

    int find(int v) {
        if(v == par[v]) return v;
        return par[v] = find(par[v]);
    }

    void Union(int u, int v) {
        u = find(u);
        v = find(v);

        if(v != u) {
            if(rank[u] == rank[v]){
                rank[u]++;
                par[v] = u;
            }
            else if(rank[u] > rank[v])
                par[v] = u;
            else par[u] = v;
        }

    }
  public:
    ll minimumCost(int n, vector<edge>& E) {
        build(n);
        sort(all(E), [&](edge& e1, edge& e2) {
            return e1.w < e2.w;
        });

        int components = n;
        ll ans = 0;
        for(auto [u, v, w] : E) {
            if(find(u) == find(v)) continue;
            ans += w;
            Union(u, v);
            components--;
        }

        if(components > 1) return -1;
        return ans;
    }
};

int main() {
    fastio

    int n, m;
    cin >> n >> m;

    vector<edge> E(m);
    loop(i, 0, m) {
        cin >> E[i].u >> E[i].v >> E[i].w;
    }

    Solution sol;
    ll ans = sol.minimumCost(n, E);
    if(ans == -1) cout << "IMPOSSIBLE";
    else cout << ans;

    return 0;
}