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

    int n, x;
    cin >> n >> x;

    vector<int> costs(n);
    take(costs, n);

    vector<int> pages(n);
    take(pages, n);

    vector<vector<int>> dp(2, vector<int>(x + 1, 0));
    loop(i, costs[0], x + 1) dp[0][i] = pages[0];
    
    int prev = 0, curr = 1;
    loop(i, 1, n){
        loop(j, 1, x + 1){
            if(costs[i] <= j)
                dp[curr][j] = max(dp[prev][j], pages[i] + dp[prev][j - costs[i]]);
            else dp[curr][j] = dp[prev][j];
        }
        swap(prev, curr);
    }

    cout << dp[prev][x];
    return 0;
}