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

int main() {
    fastio

    int n, m, q;
    cin >> n >> m >> q;

    vector<vector<ll>> G(n + 1, vector<ll>(n + 1, LLONG_MAX));
    loop(i, 0, m){
        int u, v;
        ll w;
        cin >> u >> v >> w;
        G[u][v] = min(G[u][v], w);
        G[v][u] = min(G[v][u], w);
    }

    loop(i, 1, n + 1)
        G[i][i] = 0;

    loop(k, 1, n + 1){
        loop(i, 1, n + 1){
            if(G[i][k] == LLONG_MAX) continue;
            loop(j, 1, n + 1){
                if(G[k][j] == LLONG_MAX) continue;
                G[i][j] = min(G[i][j], G[i][k] + G[k][j]);
            }
        }
    }

    while(q--){
        int u, v;
        cin >> u >> v;
        cout << (G[u][v] == LLONG_MAX ? -1 : G[u][v]) << endl;
    }

    return 0;
}