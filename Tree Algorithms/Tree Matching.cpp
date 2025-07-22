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

int ans = INT_MIN;
void solve(int idx, vector<vector<int>>& edges, vector<bool>& vis, int n, int matches){
    if(idx == n - 1){
        ans = max(ans, matches);
        return;
    }
    int u = edges[idx][0];
    int v = edges[idx][1];

    if(!vis[u] && !vis[v]){
        vis[u] = vis[v] = true;
        solve(idx + 1, edges, vis, n, matches + 1);
        vis[u] = vis[v] = false;
    }
    solve(idx + 1, edges, vis, n, matches);
}

    int main()
{
    fastio

    int n;
    cin >> n;

    vector<vector<int>> edges(n - 1, vector<int>(2, -1));
    for(int i = 0; i < n - 1; i++)
        cin >> edges[i][0] >> edges[i][1];

    vector<bool> vis(n + 1, false);

    solve(0, edges, vis, n - 1, 0);
    cout << ans << endl;
    return 0;
}