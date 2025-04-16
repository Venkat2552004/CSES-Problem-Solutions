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

    int n;
    cin >> n;

    vector<int> dp(6, 0);
    dp[0] = 1;
    
    for(int i = 1; i <= n; i++){
        for(int j = 5; j >= 1; j--){
            if(i - j >= 0)
                dp[i % 6] = (dp[i % 6] + dp[(i - j) % 6]) % mod;
        }
    }

    cout << dp[n % 6];
    return 0;
}