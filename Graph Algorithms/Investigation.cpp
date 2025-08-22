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
    void investigation(int n, vector<vector<pair<int, int>>>& G) {
        vector<ll> dist(n + 1, LLONG_MAX), route_dp(n + 1, 0);
        vector<int> min_dp(n + 1, INT_MAX), max_dp(n + 1, 0);

        priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;

        pq.push({0, 1});
        dist[1] = 0;
        route_dp[1] = 1;
        min_dp[1] = max_dp[1] = 0;

        while(!pq.empty()) {
            auto [w, u] = pq.top();
            pq.pop();

            for(auto [v, cost] : G[u]) {
                if(w + cost < dist[v]) {
                    dist[v] = w + cost;
                    pq.push({w + cost, v});

                    route_dp[v] = route_dp[u];
                    min_dp[v] = min_dp[u] + 1;
                    max_dp[v] = max_dp[u] + 1;
                }
                else if(w + cost == dist[v]) {
                    route_dp[v] += route_dp[u];
                    route_dp[v] %= mod;
                    min_dp[v] = min(min_dp[v], min_dp[u] + 1);
                    max_dp[v] = max(max_dp[v], max_dp[u] + 1);
                }
            }
        }

        cout << dist[n] << " " << route_dp[n] << " " << min_dp[n] << " " << max_dp[n];
    }
};

int main() {
    fastio

    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> G(n + 1);

    loop(i, 0, m) {
        int u, v, w;
        cin >> u >> v >> w;
        G[u].push_back({v, w});
    }

    Solution sol;
    sol.investigation(n, G);

    return 0;
}