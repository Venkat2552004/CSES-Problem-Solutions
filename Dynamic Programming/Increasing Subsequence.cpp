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

    // Vector to store the smallest possible last elements of increasing subsequences
    vector<ll> lis;

    for (int i = 0; i < n; i++) {
        // Find the position where nums[i] can replace an element in lis
        auto it = lower_bound(lis.begin(), lis.end(), nums[i]);
        if (it == lis.end()) {
            // If nums[i] is greater than all elements in lis, extend the lis
            lis.push_back(nums[i]);
        } else {
            // Otherwise, replace the element at the found position
            // ofc it disrupts the subsequence but it still not changing out answer.
            // we don't need the elements but the lenght of max possible
            *it = nums[i];
        }
    }

    // The size of lis is the length of the longest increasing subsequence
    cout << lis.size();

    return 0;
}