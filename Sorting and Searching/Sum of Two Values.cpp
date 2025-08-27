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
    void getPositions(int n, int k, vector<pair<int, int>>& arr) {
        sort(all(arr), [&](auto a, auto b) {
            return a.first < b.first;
        });

        int i = 0, j = n - 1;
        while(i < j) {
            int sum = arr[i].first + arr[j].first;
            if(sum == k){
                cout << arr[i].second << " " << arr[j].second;
                return;
            }
            if(sum > k) j--;
            else i++;
        }
        cout << "IMPOSSIBLE";
    }
};

int main() {
    fastio

    int n, k;
    cin >> n >> k;

    vector<pair<int, int>> arr(n);
    loop(i, 0, n) {
        int x;
        cin >> x;
        arr[i] = {x, i + 1};
    }

    Solution sol;
    sol.getPositions(n, k, arr);

    return 0;
}