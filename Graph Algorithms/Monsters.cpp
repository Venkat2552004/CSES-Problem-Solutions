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
    vector<vector<char>> move;
    vector<vector<int>> monster_time;

    vector<int> dx = {-1, 1, 0, 0};
    vector<int> dy = {0, 0, -1, 1};
    vector<char> dir = {'U', 'D', 'L', 'R'};
    vector<char> dirRev = {'D', 'U', 'R', 'L'};
  public:
    void safePath(int n, int m, vector<vector<char>>& mat){
        queue<pair<int, int>> q;
        pair<int, int> st;

        loop(i, 0, n) {
            loop(j, 0, m) {
                if(mat[i][j] == 'M')
                    q.push({i, j});
                else if(mat[i][j] == 'A')
                    st = {i, j};
            }
        }

        monster_time.resize(n, vector<int>(m, INT_MAX));
        int time = 0;
        while(!q.empty()) {
            int sz = q.size();
            while(sz--) {
                auto [i, j] = q.front();
                q.pop();

                if(monster_time[i][j] != INT_MAX)
                    continue;
                monster_time[i][j] = time;

                for(int k = 0; k < 4; k++) {
                    int nr = i + dx[k];
                    int nc = j + dy[k];

                    if(nr >= 0 && nr < n && nc >= 0 && nc < m){
                        if(mat[nr][nc] != '#' && monster_time[nr][nc] == INT_MAX){
                            q.push({nr, nc});
                        }
                    }
                }
            }
            time++;
        }


        move.resize(n, vector<char> (m, '#'));
        pair<int, int> end;
        bool foundPath = false;

        time = 0;
        move[st.first][st.second] = 'A';
        q.push(st);

        while(!q.empty() && !foundPath) {
            int sz = q.size();
            while(sz--) {
                auto [i, j] = q.front();
                q.pop();

                if(i == 0 || i == n - 1 || j == 0 || j == m - 1){
                    foundPath = true;
                    end = {i, j};
                    break;
                }

                for(int k = 0; k < 4; k++) {
                    int nr = i + dx[k];
                    int nc = j + dy[k];
                    char D = dir[k];

                    if(nr >= 0 && nr < n && nc >= 0 && nc < m){
                        if(mat[nr][nc] != '#' && move[nr][nc] == '#' && (time + 1 < monster_time[nr][nc])){
                            move[nr][nc] = D;
                            q.push({nr, nc});
                        }
                    }
                }
            }
            time++;
        }

        if(!foundPath){
            cout << "NO";
            return;
        }

        cout << "YES\n";
        int moves = 0;

        vector<char> path;
        auto [cr, cc] = end;

        while(move[cr][cc] != 'A'){
            char D = move[cr][cc];
            path.push_back(D);

            for(int k = 0; k < 4; k++) {
                if(dirRev[k] == D){
                    cr += dx[k];
                    cc += dy[k];
                    break;
                }
            }

            moves++;
        }

        cout << moves << endl;
        loopRev(i, path.size() - 1, 0) cout << path[i];

    }
};

int main() {
    fastio

    int n, m;
    cin >> n >> m;

    vector<vector<char>> mat(n, vector<char>(m));
    loop(i, 0, n)
        loop(j, 0, m)
            cin >> mat[i][j];
    
    Solution sol;
    sol.safePath(n, m, mat);

    return 0;
}