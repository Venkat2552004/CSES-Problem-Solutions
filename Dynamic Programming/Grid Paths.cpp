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
#define loopRev(var, start, end) for(int var = start; var >= end; var--)
#define newline cout << endl
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);

const ll mod = 1e9 + 7;

int main() {
    fastio

    int n;
    cin >> n;

    vector<vector<char>> grid(n, vector<char> (n, ' '));
    loop(i, 0, n) take(grid[i], n);

    vector<vector<int>> dp(2, vector<int> (n, 0));
    if(grid[0][0] == '.') dp[0][0] = 1;

    loop(i, 1, n)
        if(grid[0][i] == '.') dp[0][i] = dp[0][i - 1];

    int prev = 0, curr = 1;
    loop(i, 1, n){
        if(grid[i][0] == '.') dp[curr][0] = dp[prev][0];
        else dp[curr][0] = 0;
        loop(j, 1, n){
            if(grid[i][j] == '*') dp[curr][j] = 0;
            else dp[curr][j] = (dp[prev][j] + dp[curr][j - 1]) % mod;
        }
        swap(prev, curr);
    }

    cout << dp[prev][n - 1];

    return 0;
}