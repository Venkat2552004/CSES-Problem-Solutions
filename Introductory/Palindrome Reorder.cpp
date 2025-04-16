#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ul unsigned long
#define ull unsigned long long
#define takeInput(arr, n) for(int i = 0; i < n; i++) cin >> arr[i];

ll mod = 1e9 + 7;

int main() {
    string str;
    cin >> str;

    vector<int> freq(26, 0);

    for(char c : str){
        freq[c - 'A']++;
    }

    char c;
    int cnt = 0;
    for(int i = 0; i < 26; i++){
        if(freq[i] & 1) {
            c = i + 'A';
            cnt++;
            if(cnt > 1) break;
        }
        freq[i] /= 2;
    }

    if(cnt > 1){
        cout << "NO SOLUTION";
        return 0;
    }
    string pre = "", suf = "";
    for(int i = 0; i < 26; i++){
        if(freq[i] > 0){
            pre = pre + string(freq[i], i + 'A');
            suf = string(freq[i], i + 'A') + suf;
        }
    }
    if(cnt == 1) cout << pre + c + suf;
    else cout << pre + suf;
    return 0;
}