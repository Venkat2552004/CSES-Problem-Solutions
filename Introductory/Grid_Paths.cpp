#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ul unsigned long
#define ull unsigned long long
#define take(arr, n) for(int i = 0; i < n; i++) cin >> arr[i];
#define print(arr) for(auto i : arr) cout << i << ' ';
#define println(arr) for(auto i : arr) cout << i << endl;
#define sort(arr) sort(arr.begin(), arr.end())
#define sum(arr) accumulate(arr.begin(), arr.end(), 0)
#define all(arr) arr.begin(), arr.end()

ll mod = 1e9 + 7;

void calculatePaths(string& desc,vector<vector<bool>>& vis, int idx, int row, int col, int& ans){
    if(idx == 47){
        ans += (row == 6 && col == 0);
        //cout << ans;
        return;
    }

    if(row < 0 || row >= 7 || col < 0 || col >= 7) return;
    if(vis[row][col]) return;

    vis[row][col] = true;
    switch(desc[idx]) {
        case 'U' :
                calculatePaths(desc, vis, idx + 1, row - 1, col, ans);
            break;
        case 'D' :
                calculatePaths(desc, vis, idx + 1, row + 1, col, ans);
            break;
        case 'L' :
                calculatePaths(desc, vis, idx + 1, row, col - 1, ans);
            break;
        case 'R' :
                calculatePaths(desc, vis, idx + 1, row, col + 1, ans);
            break;
        case '?':
            //cout << idx << endl;
            calculatePaths(desc, vis, idx + 1, row - 1, col, ans);
            calculatePaths(desc, vis, idx + 1, row + 1, col, ans);
            calculatePaths(desc, vis, idx + 1, row, col - 1, ans);
            calculatePaths(desc, vis, idx + 1, row, col + 1, ans);
            break;
    }
    //vis[row][col] = false;

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string desc;
    cin >> desc;

    int ans = 10;
    vector<vector<bool>> vis(7, vector<bool>(7, false));
    calculatePaths(desc, vis, 0, 0, 0, ans);
    cout << ans;
    //cout << desc.length();
    return 0;
}