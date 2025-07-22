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
        vector<ll> t, unPropVal;
        int size;
    public:
        SegTree(int n){
            t.assign(4 * n, 0);
            unPropVal.assign(4 * n, 0);
            int size = 4 * n;
        }

        void build(vector<int>& arr, int v, int tl, int tr){
            if(tl == tr){
                t[v] = arr[tl];
                return;
            }
            int tm = (tl + tr) >> 1;
            build(arr, 2 * v, tl, tm);
            build(arr, v * 2 + 1, tm + 1, tr);
            t[v] = t[v * 2] + t[v * 2 + 1];
        }

        ll query(int v, int tl, int tr, int idx){
            if(idx < tl || idx > tr)
                return 0LL;
            push(v, tl, tr);
            if(tl == tr)
                return t[v];
            int tm = (tl + tr) >> 1;
            if(idx <= tm)
                return query(v * 2, tl, tm, idx);
            return query(v * 2 + 1, tm + 1, tr, idx);
        }

        void update(int v, int tl, int tr, int l, int r, int val){
            if(tr < l || tl > r || l > r) return;
            if(tl >= l && tr <= r){
                unPropVal[v] += val;
                push(v, tl, tr);
                return;
            }
            int tm = (tl + tr) >> 1;
            update(2 * v, tl, tm, l, r, val);
            update(2 * v + 1, tm + 1, tr, l, r, val);
            t[v] = t[v * 2] + t[v * 2 + 1];
        }
        
        void push(int v, int tl, int tr){
            if(unPropVal[v] == 0) return;
            t[v] += (tr - tl + 1) * unPropVal[v];
            if(tl != tr){
                unPropVal[2 * v] += unPropVal[v];
                unPropVal[2 * v + 1] += unPropVal[v];
            }
            unPropVal[v] = 0;
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
            int l, r, val;
            cin >> l >> r >> val;
            l--, r--;
            obj.update(1, 0, n - 1, l, r, val);
        }
        else{
            int idx;
            cin >> idx;
            cout << obj.query(1, 0, n - 1, idx - 1) << endl;
        }
    }

    return 0;
}