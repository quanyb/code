//rmq
#include <bits/stdc++.h>
using namespace std;

#define Vani "task"
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
const int oo = 1e18 + 7;

int n, m;
int a[N], bl[N];
int blz;

int pos (int idx) {
    return (idx - 1) / blz + 1;
}

void update (int idx, int val) {
    a[idx] = val;
    int p = pos(idx);
    int l = (p - 1) * blz + 1;
    int r = min((p * blz), n);
    bl[p] = oo;
    For (i, l, r) minimize (bl[p], a[i]);
}

int get (int l, int r) {
    int ans = oo, pl = pos(l), pr = pos(r);
    if (pl == pr) {
        For (i, l, r) minimize (ans, a[i]);
        return ans;
    }
    For (i, l, min(n, pl * blz)) minimize (ans, a[i]);
    Fod (i, r, (pr - 1) * blz + 1) minimize (ans, a[i]);
    For (i, pl + 1, pr - 1) minimize (ans, bl[i]);
    return ans;
}

void gtloli () {
    memset (bl, 0x3f, sizeof bl);
    cin >> n >> m;
    blz = sqrt(n);
    For (i, 1, n) {
        cin >> a[i];
        minimize (bl[pos(i)], a[i]);
    }

    For (i, 1, m) {
        int opt, x, y;
        cin >> opt >> x >> y;
        if (opt == 1) update (x, y);
        else cout << get (x, y) << '\n';
    }
}

signed main() {
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    if (fopen(Vani ".inp", "r")) {
        freopen(Vani ".inp", "r", stdin);
        freopen(Vani ".out", "w", stdout);
    }
    gtloli();
    return 0;
}
