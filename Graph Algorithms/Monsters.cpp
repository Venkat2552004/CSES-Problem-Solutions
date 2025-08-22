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
vector<char> dir = {'U', 'D', 'L', 'R'};


int main() {
    fastio

    int n, m;
    cin >> n >> m;

    vector<vector<char>> mat(n, vector<char>(m));
    queue<pair<int, int>> q;
    pair<int, int> start;

    loop(i, 0, n){
        loop(j, 0, m){
            cin >> mat[i][j];
            if(mat[i][j] == 'M')
                q.push({i, j});
            else if(mat[i][j] == 'A'){
                start = {i, j};
            }
        }
    }

    vector<vector<int>> monster_time(n, vector<int>(m, -1));

    int time = 0;
    while(!q.empty()){
        int sz = q.size();
        while(sz--){
            auto &[i, j] = q.front();
            q.pop();

            if(monster_time[i][j] != -1) continue;
            monster_time[i][j] = time;
            
            for(int k = 0; k < 4; k++){
                int nr = i + dx[k];
                int nc = j + dy[k];
                if(nr >= 0 && nr < n && nc >= 0 && nc < m 
                && mat[nr][nc] != '#' && monster_time[nr][nc] == -1)
                    q.push({nr, nc});
            }
        }
        time++;
    }

    vector<vector<pair<int, int>>> parent(n, vector<pair<int, int>>(m, {-1, -1}));
    pair<int, int> end = {-1, -1};

    q.push(start);
    time = 0;
    bool flag = false;
    while(!q.empty() && !flag) {
        int sz = q.size();
        while(sz--) {
            auto [i, j] = q.front();
            q.pop();
    
            if(i == 0 || i == n - 1 || j == 0 || j == n - 1) {
                end = {i, j};
                flag = true;
                break;
            }

            for(int k = 0; k < 4; k++) {
                int nr = i + dx[k];
                int nc = j + dy[k];
    
                if(nr >= 0 && nr < n && nc >= 0 && nc < m){
                    auto [pr, pc] = parent[nr][nc];
                    if(pr == -1 && pc == -1 && mat[nr][nc] == '.' && time + 1 < monster_time[nr][nc]){
                        parent[nr][nc] = {i, j};
                        q.push({nr, nc});
                    }
                }
            }
        }
        time++;
    }

    if(!flag){
        cout << "NO\n";
        return 0;
    }

    vector<char> path;
    auto curr = end;
    while(curr != start) {
        auto [i, j] = curr;
        auto [pr, pc] = parent[i][j];
        for(int k = 0; k < 4; k++){
            if(i - pr == dx[k] && j - pc == dy[k]){
                path.push_back(dir[k]);
            }
        }
        curr = parent[i][j];
    }

    reverse(all(path));
    cout << "YES\n" << path.size() << "\n";
    for(char c : path) cout << c;


    
        

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