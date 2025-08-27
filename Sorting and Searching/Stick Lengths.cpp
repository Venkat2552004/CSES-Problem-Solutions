#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ul unsigned long
#define ull unsigned long long
#define take(A, N) for(int idx = 0; idx < N; idx++) cin >> A[idx]
#define print(A) for(auto element : A) cout << element << ' '
#define println(A) for(auto element : A) cout << element << endl
#define sum(A) accumulate(A.begin(), A.end(), 0)
#define all(A) A.begin(), A.end()
#define loop(var, start, end) for(int var = start; var < end; var++)
#define loopRev(var, start, end) for(int var = start; var >= end; var--)
#define newline cout << "\n"
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);

const ll mod = 1e9 + 7;

class Solution {
  private:
    
  public:
    ll minTotalCost(int n, vector<int>& arr) {
        ll avg = (accumulate(all(arr), 0LL) +  1) / n;
       
        ll ans = 0;
        for(int num : arr) {
            ans += abs(num - avg);
        }

        return ans;
    }
};

int main() {
    fastio

    int n;
    cin >> n;

    vector<int> arr(n);
    take(arr, n);

    Solution sol;
    cout << sol.minTotalCost(n, arr);

    return 0;
}