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
    vector<int> cyclePath(int n, vector<vector<int>>& G) {
        vector<int> vis(n + 1);
        vector<int> parent(n + 1);

        int cycPoint = -1;
        stack<pair<int, int>> st;

        for(int i = 1; i <= n; i++){
            if(vis[i]) continue;
            st.push({i, -1});
            while(!st.empty() && cycPoint == -1) {
                auto [node, par] = st.top();
                vis[node] = 1;
                parent[node] = par;

                bool flag = false;

                for(int child : G[node]) {
                    if(vis[child] == 0) {
                        flag = true;
                        st.push({child, node});
                        
                    }
                    else if(vis[child] == 1) {
                        cycPoint = child;
                        parent[child] = node;
                        break;
                    }
                }

                if(!flag){
                    vis[node] = 2;
                    st.pop();
                }
            }
        }

        if(cycPoint == -1) return {};

        vector<int> ans;
        int node = cycPoint;
        ans.push_back(node);
        while(parent[node] != cycPoint){
            node = parent[node];
            ans.push_back(node);
        }
        ans.push_back(cycPoint);
        reverse(all(ans));

        return ans;
    }
};

int main() {
    fastio

    int n, m;
    cin >> n >> m;

    vector<vector<int>> G(n + 1);
    loop(i, 0, m){
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
    }

    Solution sol;
    vector<int> ans = sol.cyclePath(n, G);
    if(ans.size() == 0)
        cout << "IMPOSSIBLE";
    else {
        cout << ans.size() << endl;
        print(ans);
    }

    return 0;
}