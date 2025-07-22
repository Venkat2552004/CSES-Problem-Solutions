#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ul unsigned long
#define ull unsigned long long
#define take(A, N) for(int idx = 0; idx < N; idx++) cin >> A[idx];
#define print(A) for(auto element : A) cout << element << ' ';
#define println(A) for(auto element : A) cout << element << endl;
#define sum(A) accumulate(A.begin(), A.end(), 0)
#define all(A) A.begin(), A.end()
#define loop(var, start, end) for(int var = start; var < end; var++)
#define loopRev(var, start, end) for(int var = start; var >= end; var--)
#define newline cout << endl
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);

const ll mod = 1e9 + 7;

class BIT {
    private:
        vector<ll> bit;
        int size;
    public:
        BIT(int n){
            bit.assign(n + 1, 0LL);
            size = n + 1;
        }

        // for sum from 1 to idx
        ll summ(int idx){
            //idx++; coz indexes in queries are already 1-indexed
            ll ans = 0;
            for(int i = idx; i > 0; i -= (i & (-i))){
                ans += bit[i];
            }
            return ans;
        } 

        // to update value at idx to val
        void update(int idx, int val){
            //idx++;
            for(int i = idx; i < size; i += (i & (-i))){
                bit[i] += val;
            }
        }
};

int main() {
    fastio
    
    int n, q;
    cin >> n >> q;
    
    vector<int> arr(n);
    take(arr, n);

    BIT obj(n);
    for(int i = 0; i < n; i++)
        obj.update(i + 1, arr[i]);

    while(q--){
        int type;
        cin >> type;

        if(type == 1){
            int idx, val;
            cin >> idx >> val;

            obj.update(idx, val - arr[idx - 1]);

            // now since we need to replace value at idx, we need to store the new value in arr for future queries
            arr[idx - 1] = val;
        }
        else{
            int L, R;
            cin >> L >> R;
            cout << obj.summ(R) - obj.summ(L - 1) << endl;
        }
    }

    return 0;
}