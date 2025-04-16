#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ul unsigned long
#define ull unsigned long long
#define take(arr, n) for(int i = 0; i < n; i++) cin >> arr[i];
#define print(arr) for(auto i : arr) cout << i << ' ';
#define sort(arr) sort(arr.begin(), arr.end())
#define sum(arr) accumulate(arr.begin(), arr.end(), 0)
#define all(arr) arr.begin(), arr.end()

ll mod = 1e9 + 7;

bool valid(int k, int col, vector<int>& pos){
    for(int q = 0; q < k; q++){
        if(pos[q] == col || abs(q - k) == abs(pos[q] - col))
            return false;
    }
    return true;
}

void findWays(vector<string>& board, vector<int>& pos, int k,int& ans){
    if(k == 8){
        ans++;
        return;
    }

    for(int col = 0; col < 8; col++){
        if(board[k][col] != '*' && valid(k, col, pos)){
            pos[k] = col;
            //cout << k << "th queen place at " << col << endl; 
            findWays(board, pos, k + 1, ans);
        }
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<string> board(8);
    for(int i = 0; i < 8; i++)
        cin >> board[i];

    vector<int> pos(8, -1);

    int ans = 0;
    findWays(board, pos, 0, ans);
    cout << ans;  
    return 0;
}