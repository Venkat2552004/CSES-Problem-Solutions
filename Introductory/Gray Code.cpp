#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ul unsigned long
#define ull unsigned long long
#define takeInput(arr, n) for(int i = 0; i < n; i++) cin >> arr[i];
#define print(arr) for(auto i : arr) cout << i << ' ';
#define println(arr) for(auto i : arr) cout << i << endl;

    ll mod = 1e9 + 7;

int main() {
    int n;
    cin >> n;

    vector<string> ans;
    ans.push_back("0");
    ans.push_back("1");
    
    for(int i = 1; i < n; i++){
        vector<string> temp;
        int m = ans.size();
        for(int j = 0; j < m; j++){
            temp.push_back("0" + ans[j]);
        }
        for(int j =  m - 1; j >= 0; j--){
            temp.push_back("1" + ans[j]);
        }
        ans = temp;
    }
    println(ans)
    return 0;
}