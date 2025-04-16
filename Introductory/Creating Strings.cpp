#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ul unsigned long
#define ull unsigned long long
#define takeInput(arr, n) for(int i = 0; i < n; i++) cin >> arr[i];

ll mod = 1e9 + 7;

void generateStrings(vector<int> &freq, int idx, int n, string str, set<string>& s){
    if(idx == n){
        s.insert(str);
        return;
    }

    for(int i = 0; i < 26; i++){
        if(freq[i] != 0){
            freq[i]--;
            char c = i + 'a';
            generateStrings(freq, idx + 1, n, str + c, s);
            freq[i]++;
        }
    }
}

int main() {
    string str;
    cin >> str;

    vector<int> freq(26, 0);
    for(char c : str){
        freq[c - 'a']++;
    }

    set<string> s;
    generateStrings(freq, 0, str.size(), "", s);
    cout << s.size() << endl;
    for(auto it : s)
        cout << it << endl;
    return 0;
}