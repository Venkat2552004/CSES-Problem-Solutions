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

// Function to calculate modular inverse of a number wrt to mod
int modInverse(int a, int m){
    // inverse(a) wrt to mod 'm' is (a ^ (m - 2) % m);
    int res = 1;
    int b = m - 2;
    while(b > 0){
        if(b & 1)
            res = (res * 1LL * a) % mod;
        a = (a * 1LL * a) % mod;
        b /= 2;
    }
    return res;

}

int main() {
    fastio

    int n;
    cin >> n;

    int sum = n * (n + 1) / 2;

    // if total sum is odd, we cannot divide nums into 2 sets such that both have same sum
    if(sum & 1){
        cout << 0;
        return 0;
    }

    sum /= 2;

    // dp[i][j] = no.of ways to make sum = j using 1st i numbers.
    vector<vector<int>> dp(n + 1, vector<int>(sum + 1, 0));
    loop(i, 0, n + 1) dp[i][0] = 1;

    loop(i, 1, n + 1){
        loop(j, 1, sum + 1){
            if(i > j) // cannot use the i value to the sum
                dp[i][j] = dp[i - 1][j]; // same as previous row
            else // can use the i value or skip. so ways = take + skip
                dp[i][j] = (dp[i - 1][j] + dp[i - 1][j - i]) % mod;
        }
    }

    // Use modular inverse to divide by 2 under modulo
    // 1LL to avoid intermediate overflow
    // values stored in dp[i][j] are modded with 1e9 + 7.
    // so simply dp[i][j] / 2 won't give the correct value.
    // we have to do (dp[i][j] * (inverse(2)) with respect to mod(1e9 + 7))
    cout << (dp[n][sum] * 1LL * modInverse(2, mod)) % mod;

    return 0;
}