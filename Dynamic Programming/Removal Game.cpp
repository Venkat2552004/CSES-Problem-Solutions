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

    vector<ll> nums(n);
    take(nums, n);

    vector<ll> psum(n);
    psum[0] = nums[0];
    loop(i, 1, n) psum[i] = psum[i - 1] + nums[i];

    // dp[i][j] = max score player 1 can get from ith to jth element
    vector<vector<ll>> dp(n, vector<ll>(n, 0));
    
    //if selected ith ele to take, we want to know score i + 1 to j
    // if selected jth ele to take, we want to know i to j - 1
    // if(i + 1 to j)  is min, we'll take ith ele else we take jth ele.
    // because that is other player scores and we want to minimize it
    // because both plays optimal

    loopRev(i, n - 1, 0){
        loop(j, i, n){
            // if we have one element only, we'll take it
            if(i == j)
                dp[i][j] = nums[i];
            // if we have 2 elements, we will take the maximum one
            else if(j - i == 1)
                dp[i][j] = max(nums[i], nums[j]);
            else{
                ll x = psum[j];
                if(i > 0) x -= psum[i - 1];
                // total sum from i t0 j is 'x'. if other player gets 'y' from total, i get (x - y)
                ll take_ith = x - dp[i + 1][j];
                ll take_jth = x - dp[i][j - 1];
                dp[i][j] = max(take_ith, take_jth);
            }
        }
    }

    cout << dp[0][n - 1];

    return 0;
}