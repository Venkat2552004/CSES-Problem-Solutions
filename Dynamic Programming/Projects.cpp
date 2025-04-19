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

struct project {
    ll start;
    ll end;
    ll reward;
};

int binarySearch_ceil(int l, int h, int k, vector<project> &projects) {
    int res = -1;
    while (l <= h) {
        int mid = l + (h - l) / 2;
        if (projects[mid].end < k) {
            res = mid;
            l = mid + 1;
        } else {
            h = mid - 1;
        }
    }
    return res;
}

int main() {
    fastio

    int n;
    cin >> n;

    vector<project> projects(n);
    loop(i, 0, n){
        cin >> projects[i].start;
        cin >> projects[i].end;
        cin >> projects[i].reward;
    }

    auto customSort = [&](project a, project b){
        return a.end < b.end;
    };

    sort(all(projects), customSort);

    vector<ll> dp(n, 0);
    dp[0] = projects[0].reward;

    loop(i, 1, n){
        // dont take the current project or take only the current project
        dp[i] = max(dp[i - 1], projects[i].reward);
        // Take the current project after completion of some previous project
        int idx = binarySearch_ceil(0, i - 1, projects[i].start, projects);
        if (idx != -1)
            dp[i] = max(dp[i], projects[i].reward + dp[idx]);
    }

    cout << dp[n - 1];
    
    return 0;
}