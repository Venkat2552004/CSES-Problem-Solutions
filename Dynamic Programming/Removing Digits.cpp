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
    
    vector<int> dp(10, 1e9);
    loop(i, 0, 10) dp[i] = 1;

    loop(i, 10, n + 1){
        int num = i;
        dp[i % 10] = INT_MAX;
        while(num){
            int digit = num % 10;
            num /= 10;
            if(digit != 0){
                dp[i % 10] = min(dp[i % 10], 1 + dp[(i - digit) % 10]);
            }
        }
    }

    cout << dp[n % 10];
    return 0;
}