#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ul unsigned long
#define ull unsigned long long
#define mod 1000000007
#define takeInput(arr, n) for(int i = 0; i < n; i++) cin >> arr[i];

void generatePerm(int n){
    if(n == 2 || n == 3){
        cout << "NO SOLUTION";
        return;
    }

    int i = 1, j = 2;
    while(j <= n){
        cout << j << " ";
        j += 2;
    }
    while(i <= n){
        cout << i << " ";
        i += 2;
    }
}

int main() {
    int n;
    cin >> n;
    generatePerm(n);
    return 0;
}