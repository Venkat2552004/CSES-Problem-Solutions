#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ul unsigned long
#define ull unsigned long long
#define takeInput(arr, n) for(int i = 0; i < n; i++) cin >> arr[i];
#define sort(arr) sort(arr.begin(), arr.end())
#define print(arr) for(auto i : arr) cout << i << ' ';

ll mod = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> ar(n), lv(n);
    for(int i = 0; i < n; i++)
        cin >> ar[i] >> lv[i];

    sort(ar);
    sort(lv);

    int ans = 1,cust = 0, i = 0, j = 0;
    while(i < n){
        if(ar[i] <= lv[j]){
            cust++;
            ans = max(ans, cust);
            i++;
        }
        else{
            cust--;
            j++;
        }
    }

    cout << ans;
    return 0;
}