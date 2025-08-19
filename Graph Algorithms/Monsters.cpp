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

vector<int> dx = {-1, 1, 0, 0};
vector<int> dy = {0, 0, -1, 1};
vector<string> dir = {"U", "D", "L", "R"};


bool dfs(int x, int y, int n, int m, int moves, vector<vector<bool>>& vis, vector<vector<char>> mat,
            vector<vector<int>>& dist, string path, string& ans){
    if(x == 0 || x == n - 1 || y == 0 || y == m - 1){
        ans = path;
        return true;
    }

    vis[x][y] = true;
    bool flag = false;
    for(int k = 0; k < 4; k++){
        int nr = x + dx[k];
        int nc = y + dy[k];
        if(nr >= 0 && nr < n && nc >= 0 && nc < m && mat[nr][nc] == '.'
            && !vis[nr][nc] && moves + 1 < dist[nr][nc]){
                flag |= dfs(nr, nc, n, m, moves + 1, vis, mat, dist, path + dir[k], ans);
        }
        if(flag) break;
    }

    vis[x][y] = false;
    return flag;
}

int main() {
    fastio

    int n, m;
    cin >> n >> m;

    vector<vector<char>> mat(n, vector<char>(m));
    queue<pair<int, int>> q;
    int x, y;

    loop(i, 0, n){
        loop(j, 0, m){
            cin >> mat[i][j];
            if(mat[i][j] == 'M')
                q.push({i, j});
            else if(mat[i][j] == 'A'){
                x = i, y = j;
            }
        }
    }

    vector<vector<int>> dist(n, vector<int>(m, INT_MAX));

    int moves = 0;
    while(!q.empty()){
        int sz = q.size();
        while(sz--){
            auto &[i, j] = q.front();
            q.pop();

            if(dist[i][j] != INT_MAX) continue;
            dist[i][j] = moves;
            
            for(int k = 0; k < 4; k++){
                int nr = i + dx[k];
                int nc = j + dy[k];
                if(nr >= 0 && nr < n && nc >= 0 && nc < m 
                && mat[nr][nc] == '.' && dist[nr][nc] == INT_MAX)
                    q.push({nr, nc});
            }
        }
        moves++;
    }

    vector<vector<bool>> vis(n, vector<bool>(m, false));
    string ans = "";

    if(dfs(x, y, n, m, 0, vis, mat, dist, "", ans))
        cout << "YES\n" << ans.size() << endl << ans;
    else cout << "NO";

    // queue<tuple<int, int, string>> qq;
    // qq.push({x, y, ""});
    // moves = 0;
    // bool flag = false;

    // while(!qq.empty()){
    //     int sz = qq.size();
    //     while(sz--){
    //         auto [i, j, path] = qq.front();
    //         qq.pop();

    //         if(vis[i][j]) continue;
    //         vis[i][j] = true;

    //         if(i == 0 || i == n - 1 || j == 0 || j == m - 1){
    //             flag = true;
    //             ans = path;
    //             break;
    //         }

    //         for(int k = 0; k < 4; k++){
    //             int nr = i + dx[k];
    //             int nc = j + dy[k];
    //             if(nr >= 0 && nr < n && nc >= 0 && nc < m && mat[nr][nc] == '.'
    //             && !vis[nr][nc] && moves + 1 < dist[nr][nc])
    //                 qq.push({nr, nc, path + dir[k]});
    //         }
    //     }
    //     moves++;
    // }


    // if(flag)
    //     cout << "YES\n" << ans.size() << endl << ans;
    // else cout << "NO";

    return 0;
}