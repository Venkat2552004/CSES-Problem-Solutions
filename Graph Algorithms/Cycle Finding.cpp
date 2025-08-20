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
    
  public:
    void printNegCycle(int n, vector<edge>& E) {
        vector<ll> dist(n + 1, 0);
        vector<int> par(n + 1, -1);
        int cycPoint = 0;

        loop(i, 0, n){
            for(auto [u, v, w] : E) {
                if(dist[u] + w < dist[v]){
                    if(i == n - 1){
                        cycPoint = v;
                    }
                    dist[v] = dist[u] + w;
                    par[v] = u;
                }
            }
        }

        if(cycPoint == 0)
            cout << "NO";
        else{
            cout << "YES\n";
            loop(i, 0, n) cycPoint = par[cycPoint];
            int node = cycPoint;
            vector<int> cycle;
            do{
                cycle.push_back(node);
                node = par[node];
            }while(node != cycPoint);
            cycle.push_back(node);
            reverse(all(cycle));
            print(cycle);
        }
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
    sol.printNegCycle(n, E);

    return 0;
}