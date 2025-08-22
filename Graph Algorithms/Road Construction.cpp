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
    int u, v;
};

class Solution {
  private:
    vector<int> par;
    vector<int> size;

    void build(int n) {
        par.resize(n + 1);
        size.resize(n + 1);
        loop(i, 1, n + 1) {
            par[i] = i;
            size[i] = 1;
        }
    }

    int find(int v) {
        if(v == par[v]) return v;
        return par[v] = find(par[v]);
    }

    void Union(int u, int v) {
        u = find(u);
        v = find(v);

        if(v != u) {
            if(size[v] > size[u]) swap(u, v);
            par[v] = u;
            size[u] += size[v];
        }
    }
  public:
    void minimumCost(int n, vector<edge>& E) {
        build(n);

        int components = n, maxSize = 1;
        for(auto [u, v] : E) {
            if(find(u) != find(v)) {
                Union(u, v);
                components--;
                maxSize = max({maxSize, size[find(u)], size[find(v)]});
            }
            cout << components << " " << maxSize << endl;
        }
    }
    
};

int main() {
    fastio

    int n, m;
    cin >> n >> m;

    vector<edge> E(m);
    loop(i, 0, m) {
        cin >> E[i].u >> E[i].v;
    }

    Solution sol;
    sol.minimumCost(n, E);    

    return 0;
}