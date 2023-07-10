/*
    Loli has hopium for VOI 2023.
    Brain stopped working at 09:17 11.10.2022.
*/
#include <bits/stdc++.h>
using namespace std;

#define ll long long
// #define int long long
#define pii pair<int, int>
#define vi vector<int>
#define pb push_back
#define fr first
#define sc second
#define fi(x, a, b) for(int x=(int)(a); (x)<=(int)(b); ++(x))
#define fd(x, a, b) for(int x=(int)(a); (x)>=(int)(b); --(x))
const int oo=1e9+7;
const ll lloo=1e18+7;
template<class T> bool maximize(T &res, const T &val) { if (res < val) { res = val; return 1; } return 0; }
template<class T> bool minimize(T &res, const T &val) { if (res > val) { res = val; return 1; } return 0; }

#define task "CNTOCCUR"
#define nmax 1000007
const int mod = (int)1e9 + 7;

int n, m, k, x;
int res=0;
int a[nmax];
int cnt[nmax];
int ans[nmax];

void remove(int idx) {
    if(idx < 1 || idx > n || a[idx] > 1e5) return;
    if(cnt[a[idx]] == a[idx]) --res;
    cnt[a[idx]]--;
    if(cnt[a[idx]] == a[idx]) ++res;
}

void add(int idx) {
    if(idx < 1 || idx > n || a[idx] > 1e5) return;
    if(cnt[a[idx]] == a[idx]) --res;
    cnt[a[idx]]++;
    if(cnt[a[idx]] == a[idx]) ++res;
}

int block_size;

struct Query {
    int l, r, idx;
    bool operator<(Query other) const
    {
        if(l / block_size != other.l / block_size)
            return l < other.l;
        return (l / block_size)&1 ? r < other.r : r > other.r;
    }
} queries[nmax];

void loli() {
    cin >> n >> m;
    block_size = sqrt(n);
    fi(i,1,n) cin >> a[i];
    fi(i,1,m) {
        cin >> queries[i].l >> queries[i].r;
        queries[i].idx = i;
    }
    sort(queries+1, queries+m+1);
    int cur_l = 0;
    int cur_r = -1;
    for (Query q : queries) {
        while (cur_l > q.l) {
            cur_l--;
            add(cur_l);
        }
        while (cur_r < q.r) {
            cur_r++;
            add(cur_r);
        }
        while (cur_l < q.l) {
            remove(cur_l);
            cur_l++;
        }
        while (cur_r > q.r) {
            remove(cur_r);
            cur_r--;
        }
        ans[q.idx] = res;
    }
    fi(i,1,m) cout << ans[i] << '\n';
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int test = 1;
    freopen(task".INP","r",stdin);
    freopen(task".OUT","w",stdout);
    // cin >> test;
    while(test--) loli();
    return 0;
}
