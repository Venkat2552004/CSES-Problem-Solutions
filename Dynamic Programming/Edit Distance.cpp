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

    string a, b;
    cin >> a >> b;
    
    int n = a.length(), m = b.length();

    vector<vector<int>> dp(n + 1, vector<int> (m + 1, 0));
    loop(i, 1, n + 1) dp[i][0] = i;
    loop(j, 1, m + 1) dp[0][j] = j;

    loop(i, 1, n + 1){
        loop(j, 1, m + 1){
            if(a[i - 1] == b[j - 1]) // if match, continue
                dp[i][j] = dp[i - 1][j - 1];
            else
                dp[i][j] = dp[i - 1][j - 1] + 1; // else replace

            // skip ith char or add same after jth char
            dp[i][j] = min(dp[i][j], dp[i - 1][j] + 1);
            // skip jth char or add same after ith char
            dp[i][j] = min(dp[i][j], dp[i][j - 1] + 1);

            // single line exp
            //dp[i][j] = min({dp[i - 1][j - 1] + (a[i - 1] == b[j - 1]),
            //                dp[i][j - 1] + 1, dp[i - 1][j] + 1});
        }
    }
 
    cout << dp[n][m];
    return 0;
}