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

class SegTree{
    private:
        vector<int> t;
        int size;
    public:
        SegTree(int n){
            size = 4 * n;
            t.assign(size, INT_MAX);
        }

        // initial func call values: v = 1, tl = 0, tr = n - 1
        void build(vector<int>& arr, int v, int tl, int tr){
            // can divide into 2 parts anymore
            if(tl == tr){
                t[v] = arr[tl]; // t[v] = arr[tr] also works as tl = tr
                return;
            }
            // calc mid value for divide and conqure approach
            int tm = (tl + tr) / 2;
            // left child = 2 * v, right child = 2 * v + 1 (1 based indexing)
            // we started with v intial value as 1
            build(arr, 2 * v, tl, tm);
            build(arr, 2 * v + 1, tm + 1, tr);
            // since bottom-up apporach, modifications done after recursive calls
            t[v] = min(t[2 * v], t[2 * v + 1]); // change the line according to the question
            // by the time of above call, we completed calculation t[lc] and t[rc]
            // using the above 2 recursive calls.

        }
        // initial func call values : v = 1, tl = 0, tr = n - 1, l = ?, r = ?
        int query(int v, int tl, int tr, int l, int r){
            // out of range
            if(tl > r || tr < l)
                return INT_MAX;
            // complete match to the node range (v range is tl and tr)
            if(tl == l && tr == r)
                return t[v];
            // partial match  (ex v range is [2, 5] and we need [3, 5] or anything)
            int tm = (tl + tr) / 2;
            int leftMin = query(2 * v, tl, tm, l, min(tm, r));
            int rightMin = query(2 * v + 1, tm + 1, tr, max(tm + 1, l), r);
            return min(leftMin, rightMin);
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

    // using the below, i can take segment tree size as 2 * n instead of
    // 4 * n
    // while(n & (n - 1) != 0){
    //     arr.push_back(INT_MAX);
    //     n++;
    // }

    SegTree obj(n);
    obj.build(arr, 1, 0, n - 1);

    while(q--){
        int l, r;
        cin >> l >> r;
        cout << obj.query(1, 0, n - 1, l - 1, r - 1) << endl;
        // (l - 1 and r - 1) because v = 1 range is [0, n - 1]. in problems
        // l and r are given on basis of 1 indexing like [1, n]
    }

    //obj.printt();

    return 0;
}