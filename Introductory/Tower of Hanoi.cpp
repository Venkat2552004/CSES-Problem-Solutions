#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ul unsigned long
#define ull unsigned long long
#define takeInput(arr, n) for(int i = 0; i < n; i++) cin >> arr[i];

ll mod = 1e9 + 7;

void towerOfHanoi(int n,int src, int dest, int via, vector<vector<int>>& moves) {
    if(n > 0){
        towerOfHanoi(n - 1, src, via, dest, moves);
        moves.push_back({src, dest});
        towerOfHanoi(n - 1, via, dest, src, moves);
    }
}

int main() {
    int n;
    cin >> n;

    vector<vector<int>> moves;
    towerOfHanoi(n, 1, 3, 2, moves);
    cout << moves.size() << endl;
    for(auto move : moves){
        cout << move[0] << " " << move[1] << endl;
    }
    return 0;
}