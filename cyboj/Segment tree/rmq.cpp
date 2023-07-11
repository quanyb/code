#include <bits/stdc++.h>
using namespace std;
 
#define task "rmq"
#define ll long long
#define ii pair<int, int>
#define F first
#define S second
#define pb push_back
#define For(i, a, b) for (int i = (int)(a); i <= (int)(b); ++i)
#define Fod(i, a, b) for (int i = (int)(a); i >= (int)(b); --i)
 
template<class T> inline bool maximize(T &r, const T &v) {return r < v ? r = v, 1 : 0;}
template<class T> inline bool minimize(T &r, const T &v) {return r > v ? r = v, 1 : 0;}
 
const int N = 1e6 + 7;
const int oo = 1e9 + 7;
 
int n, m;
int a[N];
int st[N * 4];
 
void update (int id, int l, int r, int idx, int val) {
    if (l > idx || idx > r) return ;
    if (l == r) st[id] = val;
    else {
        int mid = (l + r) / 2;
        update (id * 2, l, mid, idx, val);
        update (id * 2 + 1, mid + 1, r, idx, val);
        st[id] = min (st[id * 2], st[id * 2 + 1]);
    }
}
 
int get (int id, int l, int r, int u, int v) {
    if (u > r || l > v) return oo;
    if (u <= l && r <= v) return st[id];
 
    int mid = (l + r) / 2;
    int L = get (id * 2, l, mid, u, v);
    int R = get (id * 2 + 1, mid + 1, r, u, v);
    return min (L, R);
}
 
void ttk32() {
    cin >> n >> m;
    For (i, 1, n) {
        cin >> a[i];
        update (1, 1, n, i, a[i]);
    }
    For (i, 1, m) {
        int opt, x, y;
        cin >> opt >> x >> y;
        if (opt == 1) update (1, 1, n, x, y);
        else cout << get (1, 1, n, x, y) << "\n"; 
    }
}
 
signed main() {
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    if (fopen(task ".inp", "r")) {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    ttk32();
    return 0;
}
