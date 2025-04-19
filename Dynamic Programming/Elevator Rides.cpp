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

int main() {
    fastio

    int n;
    cin >> n;

    ll x;
    cin >> x;

    vector<ll> weights(n);
    take(weights, n);

    int N = (1 << n);
    // dp[i] = {no.of rides for (persons in setbits of i), occupied weight}
    vector<pair<ll, ll>> dp(N, {1e9, 1e9});
    // 0 has no set bits, no person is taken {1 ride, 0 occupied space}
    dp[0] = {1, 0};

    loop(i, 1, N){
        // every i from 1 to N is represented in n bits (N = 2^n)
        loop(j, 0, n){
            if(i & (1 << j)){ // if jth bit is set
                // state before jth person is added
                int prevState = i ^ (1 << j);
                // if allowed to add this to prevState 
                if(dp[prevState].second + weights[j] <= x)
                    dp[i] = min(dp[i], {dp[prevState].first, dp[prevState].second + weights[j]});
                // if not allowed, we can take new ride for this person
                else
                    dp[i] = min(dp[i], {dp[prevState].first + 1, weights[j]});
            }

        }
    }

    cout << dp[N - 1].first;


    return 0;
}