#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ul unsigned long
#define ull unsigned long long
#define takeInput(arr, n) for(int i = 0; i < n; i++) cin >> arr[i];

ll mod = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    set<int> s;
    int x;
    while(n--){
        cin >> x;
        s.insert(x);
    }
    cout << s.size();

    return 0;
}