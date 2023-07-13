//carrays
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

const int nm = 5000009;

const long long mod = 1e9 + 7;
long long mu[nm], dp[nm];

signed main(void){
    if(fopen(Vani".inp", "r")){
        freopen(Vani".inp" ,"r", stdin);
        freopen(Vani".out", "w", stdout);
    }
    cin.tie(0)->sync_with_stdio(false);
    long long n, m, k;
    cin >> n >> m >> k;
    mu[0] = 1;
    for (int i = 1; i <= n;i++){
        mu[i] = (mu[i - 1] * m) % mod;
    }
    memset(dp, 0, sizeof(dp));
    dp[k] = m;
    for (int i = k+1; i <= n;i++){
        dp[i] = ((dp[i - 1] * m) % mod + ((mu[i - k] - dp[i - k] + mod) % mod) * (m - 1)) % mod;
    }
    cout << dp[n];
    return 0;
}
