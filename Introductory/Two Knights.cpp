#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ul unsigned long
#define ull unsigned long long
#define mod 1000000007
#define takeInput(arr, n) for(int i = 0; i < n; i++) cin >> arr[i];

int main() {
    int t;
    cin >> t;
    for(ull n = 1; n <= t; n++){
        ull totalCells = (n * n * (n * n - 1)) / 2;
        ull attack = 4 * (n - 1) * (n - 2);
        ull ans = totalCells - attack;
        cout << ans << endl;
    }
    return 0;
}