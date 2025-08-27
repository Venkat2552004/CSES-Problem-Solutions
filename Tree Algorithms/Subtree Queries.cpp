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
    vector<ll> segTree;
    vector<int> arr, time, size;

    void flatten(int u, int par, int& tm, vector<vector<int>>& G) {
        time[u] = tm;
        tm++;
        
        arr.push_back(u);

        for(int v : G[u]) {
            if(v == par) continue;
            flatten(v, u, tm, G);
            size[u] += size[v];
        }
    }

    void buildSegTree(vector<ll>& value, int v, int tl, int tr) {
        if(tl == tr) {
            segTree[v] = value[tl];
            return;
        }

        int tm = (tl + tr) >> 1;
        buildSegTree(value, 2 * v, tl, tm);
        buildSegTree(value, 2 * v + 1, tm + 1, tr);

        segTree[v] = segTree[2 * v] + segTree[2 * v + 1];
    }

    void update(int v, int pos, ll x, int tl, int tr) {
        if(tl == tr){
            segTree[v]+= x;
            return;
        }

        int tm = (tl + tr) >> 1;
        if(pos <= tm) update(2 * v, pos, x, tl, tm);
        else update(2 * v + 1, pos, x, tm + 1, tr);

        segTree[v] = segTree[2 * v] + segTree[2 * v + 1];
    }

    ll query(int v, int l, int r, int tl, int tr) {
        if(r < tl || l > tr) return 0;
        if(tl>= l && tr <= r)
            return segTree[v];

        int tm = (tl + tr) >> 1;
        ll leftAns = query(2 * v, l, r, tl, tm);
        ll rightAns = query(2 * v + 1, l, r, tm + 1, tr);

        return leftAns + rightAns;
    }
  public:
    void subTreeQueries(int n, vector<ll>& value, vector<vector<int>>& queries, vector<vector<int>>& G) {
        time.resize(n + 1, 0);
        size.resize(n + 1, 1);
        
        //making it 1-indexed
        arr.push_back(0);
        size[0] = 0;

        int tm = 1;
        flatten(1, 0, tm, G);

        vector<ll> new_values(n + 1);
        loop(i, 1, n + 1){
            new_values[i] = value[arr[i]];
        }

        segTree.resize(4 * (n + 1), 0);
        buildSegTree(new_values, 1, 1, n);

        for(auto q : queries) {
            int u = q[0], v = q[1];
            if(u == 1){
                ll x = q[2];
                update(1, time[v], x - value[v], 1, n);
                value[v] = x;
            }
            else
                cout << (long long)query(1, time[v], time[v] + size[v] - 1, 1, n) << endl;
        }

    }
};

int main() {
    fastio

    int n, q;
    cin >> n >> q;

    vector<ll> value(n + 1);
    loop(i, 1, n + 1) cin >> value[i];

    vector<vector<int>> G(n + 1);
    loop(i, 0, n - 1) {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    vector<vector<int>> query;
    loop(i, 0, q) {
        int u, v;
        cin >> u >> v;
        if(u == 1){
            int x;
            cin >> x;
            query.push_back({u, v, x});
        }
        else query.push_back({u, v});
    }

    Solution sol;
    sol.subTreeQueries(n, value, query, G);

    return 0;
}