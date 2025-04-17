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

    int n, m;
    cin >> n >> m;

    vector<int> nums(n);
    take(nums, n);

    //dp[i][j] --> number of arrays of size i such that last element is j
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    loop(j, 1, m + 1) dp[1][j] = (nums[0] == j || nums[0] == 0);

    loop(i, 2, n + 1){
        loop(j, 1, m + 1){
            if(nums[i - 1] == j || nums[i - 1] == 0){
                loop(prev, j - 1, j + 2){
                    if(prev >= 1 && prev <= m)
                        dp[i][j] = (dp[i][j] + dp[i - 1][prev]) % mod;
                }
            }
            else dp[i][j] = 0;
        }
    }

    int ans = 0;
    loop(j, 1, m + 1) ans = (ans + dp[n][j]) % mod;
    cout << ans;
    
    return 0;
}