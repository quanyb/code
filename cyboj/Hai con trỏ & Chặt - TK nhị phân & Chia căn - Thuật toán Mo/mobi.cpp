//mobi
#include <bits/stdc++.h>
#define Vani "task"

using namespace std;

#define pb push_back
#define ii pair<int, int>
#define fi first
#define se second
#define ll long long
#define sortin(a, n) sort(a, a + n)
#define all(a) a.begin(), a.end()
#define f(i, a, b) for(int i = a; i < b; i++)
#define fd(i, a, b) for(int i = a; i > b; i--)
#define el '\n'

template<class T> inline bool maximize(T &r, const T &v) {return r < v ? r = v, 1 : 0;}
template<class T> inline bool minimize(T &r, const T &v) {return r > v ? r = v, 1 : 0;}

int n, k;
const int nm = 5000009;
ii a[nm];
ll b[nm], v[nm];

signed main(void){

    if(fopen(Vani".inp", "r")){
        freopen(Vani".inp" ,"r", stdin);
        freopen(Vani".out", "w", stdout);
    }
    cin.tie(0)->sync_with_stdio(false);
    cin >> n >> k;
    for(int i = 1; i <= n; i++){
        cin >> a[i].first >> a[i].second;
    }
    sort(a + 1, a + n + 1);
    for(int i = 1; i <= n; i++){
        b[i] = a[i].first;
        v[i] = v[i-1] + a[i].second;
    }
    ll res = 0;
    for(int i = 1; i <= n; i++){
        int pos = upper_bound(b + 1, b + n + 1, b[i] + 2 * k) - b - 1;
        res = max(res, v[pos] - v[i - 1]);
    }
    cout << res;
    return 0;
}
