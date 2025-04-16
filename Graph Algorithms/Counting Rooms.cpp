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
#define newline cout << endl
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);

ll mod = 1e9 + 7;


void dfs(int row, int col, vector<vector<char>>& grid){
    int n = grid.size();
    int m = grid[0].size();

    if(row < 0 || row >= n || col < 0 || col >= m || grid[row][col] != '.') return;
    grid[row][col] = '@';
    dfs(row - 1, col, grid);
    dfs(row + 1, col, grid);
    dfs(row, col - 1, grid);
    dfs(row, col + 1, grid);
}

int main() {
    fastio

    int n, m;
    cin >> n >> m;

    vector<vector<char>> grid(n, vector<char> (m));

    for(int i = 0; i < n; i++) take(grid[i], m);

    int rooms = 0;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(grid[i][j] == '.'){
                rooms++;
                dfs(i, j, grid);
            }
        }
    }

    cout << rooms;
    
    return 0;
}