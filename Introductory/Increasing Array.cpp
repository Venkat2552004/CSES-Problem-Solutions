#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ul unsigned long
#define ull unsigned long long
#define takeInput(arr, n) for(int i = 0; i < n; i++) cin >> arr[i];

ull minOperations(vector<ull>& nums, int n){
    ull ops = 0;
    ull prev = nums[0];
    for(int i = 1; i < n; i++){
        ull curr = nums[i];
        if(curr < prev)
            ops += (prev - curr);
        else prev = curr;
    }
    return ops;
}


int main() {
    int n;
    cin >> n;
    vector<ull> nums(n);
    takeInput(nums, n);
    cout << minOperations(nums, n);
    return 0;
}