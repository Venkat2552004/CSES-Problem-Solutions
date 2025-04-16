#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ul unsigned long
#define ull unsigned long long
#define mod 1000000007

int main() {
    string str;
    cin >> str;
    int cnt = 1, ans = 1;
    for(int i = 0; str[i]; i++){
        if(str[i] == str[i - 1]){
            cnt++;
            ans = max(ans, cnt);
        }
        else
            cnt = 1;
    }
    cout << ans;
    return 0;
}