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

class SegTree {
    private:
        vector<int> t;
    public:
        SegTree(int n){
            t.assign(4 * n, INT_MAX);
        }

        void build(vector<int>& arr, int v, int tl, int tr){
            if(tl == tr){
                t[v] = arr[tl];
                return;
            }
            int tm = (tl + tr) / 2;
            build(arr, v * 2, tl, tm);
            build(arr, v * 2 + 1, tm + 1, tr);
            t[v] = min(t[v * 2], t[v * 2 + 1]);
        }

        int query(int v, int tl, int tr, int l, int r){
            if(tl > r || tr < l)
                return INT_MAX;
            if(tl == l && tr == r)
                return t[v];
            int tm = (tl + tr) / 2;
            int leftMin = query(v * 2, tl ,tm, l, min(tm, r));
            int rightMin = query(v * 2 + 1, tm + 1 ,tr, max(l, tm + 1), r);
            return min(leftMin, rightMin);
            
        }

        void update(int v, int tl, int tr, int idx, int val){
            //if(idx < tl || idx > tr) return;
            if(tl == tr) {
                t[v] = val;
                return;
            };
            int tm = (tl + tr) / 2;
            if(idx <= tm)
                update(v * 2, tl, tm, idx, val);
            else
                update(v * 2 + 1, tm + 1, tr, idx, val);
            t[v] = min(t[v * 2], t[v * 2 + 1]);
        }

        void printt(){
            print(t);
        }
};

int main() {
    fastio

    int n, q;
    cin >> n >> q;

    vector<int> arr(n);
    take(arr, n);

    SegTree obj(n);
    obj.build(arr, 1, 0, n - 1);

    while(q--){
        int type;
        cin >> type;
        
        if(type == 1){
            int idx, val;
            cin >> idx >> val;
            idx--;
            obj.update(1, 0, n - 1, idx, val);
        }
        else{
            int l, r;
            cin >> l >> r;
            l--, r--;
            cout << obj.query(1, 0, n - 1, l, r) << endl;
        }
    }

    return 0;
}