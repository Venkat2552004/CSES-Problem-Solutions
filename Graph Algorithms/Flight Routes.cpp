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
    vector<ll> minimumKCosts(int n, int k, vector<vector<pair<int, int>>>& G) {
        vector<int> vis(n + 1);
        //priority_queue<ll> mxh;
        priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
        
        pq.push({0, 1});
        
        vector<ll> ans;
        while(!pq.empty()) {
            auto [w, node] = pq.top();
            pq.pop();

            if(vis[node] == k) continue;
            vis[node]++;

            if(node == n){
                ans.push_back(w);
                //if(mxh.size() > k) mxh.pop();
            }

            for(auto [adjNode, cost] : G[node]) {
                pq.push({cost + w, adjNode});
            }
        }

        sort(all(ans));
        return ans;
    }
};

int main() {
    fastio

    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<pair<int, int>>> G(n + 1);
    loop(i, 0, m){
        int u, v, w;
        cin >> u >> v >> w;
        G[u].push_back({v, w});
    }

    Solution sol;
    print(sol.minimumKCosts(n, k, G))

    return 0;
}