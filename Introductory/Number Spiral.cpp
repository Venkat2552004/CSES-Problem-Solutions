#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ul unsigned long
#define ull unsigned long long
#define mod 1000000007
#define takeInput(arr, n) for(int i = 0; i < n; i++) cin >> arr[i];

ull solve(ull x, ull y, ull cell, ull cellVal){
    if(x == y) return cellVal;
    if(x > y){
        if(cell & 1) return cellVal + (x - y);
        else return cellVal - (x - y);
    }
    else{
        if(cell & 1) return cellVal - (y - x);
        else return cellVal + (y - x); 
    }
}

int main(){
    int t;
    cin >> t;
    while(t--){
        ull x, y;
        cin >> x >> y;
        
        ull cell = max(x, y) - 1;
        ull cellVal = 1 + 2 * ((cell * (cell + 1)) / 2);

        cout << solve(x, y, cell, cellVal) << endl;
    }
    return 0;
}