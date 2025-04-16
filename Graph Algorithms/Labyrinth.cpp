#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ul unsigned long
#define ull unsigned long long
#define take(A, N) for(int idx = 0; idx < N; idx++) cin >> A[idx];
#define print(A) for(auto element : A) cout << element << ' ';
#define println(A) for(auto element : A) cout << element << endl;
#define sort(A) sort(A.begin(), A.end())
#define sum(A) accumulate(A.begin(), A.end(), 0)
#define all(A) A.begin(), A.end()
#define loop(var, start, end) for(int var = start; var < end; var++)
#define newline cout << endl
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);

ll mod = 1e9 + 7;



int main() {
    fastio

    int n, m;
    cin >> n >> m;

    vector<vector<char>> grid(n, vector<char> (m));
    int sr = -1, sc = -1;

    loop(i, 0, n){
        loop(j, 0, m){
            cin >> grid[i][j];
            if(grid[i][j] == 'A'){
                sr = i;
                sc = j;
            }
        }
    }

    vector<vector<bool>> vis(n, vector<bool>(m, false));
    vector<vector<pair<int, int>>> par(n, vector<pair<int, int>> (m, {-1, -1}));
    vector<vector<char>> DIR(n, vector<char> (m, ' '));
    vector<int> dx = {-1, 1, 0, 0};
    vector<int> dy = {0, 0, -1, 1};
    vector<char> dir = {'U', 'D', 'L', 'R'};
    
    queue<pair<int, int>> q;
    q.push({sr, sc});
    vis[sr][sc] = true;

    int er = -1, ec = -1;
    bool isPath = false;
    while(!q.empty() && !isPath){
        auto [r, c] = q.front();
        q.pop();

        for(int i = 0; i < 4; i++){
            int nr = r + dx[i];
            int nc = c + dy[i];
            if (nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] != '#' &&!vis[nr][nc]){
                q.push({nr, nc});
                vis[nr][nc] = true;
                par[nr][nc] = {r, c};
                DIR[nr][nc] = dir[i];

                if(grid[nr][nc] == 'B'){
                    isPath = true;
                    er = nr;
                    ec = nc;
                    break;
                }
            }
        }
    }

    if(!isPath){
        cout << "NO";
        return 0;
    }

    int r = er, c = ec;
    string path = "";
    while(grid[r][c] != 'A'){
        path += DIR[r][c];
        auto [pr, pc] = par[r][c];
        r = pr, c = pc;
    }

    reverse(all(path));
    cout << "YES\n" << path.length() << endl << path;
    

    return 0;
}