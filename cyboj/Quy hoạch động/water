#include <bits/stdc++.h>
#define Vani ""

using namespace std;

#define pb push_back
#define ii pair<int, int>
#define fi first
#define se second
#define ll long long
#define sortin(a, n) sort(a, a + n)
#define all(a) a.begin(), a.end()
#define el '\n'

template<class T> inline bool maximize(T &r, const T &v) {return r < v ? r = v, 1 : 0;}
template<class T> inline bool minimize(T &r, const T &v) {return r > v ? r = v, 1 : 0;}

const int oo = INT_MAX;
int n, m, k, x;
int res = oo;
int c[21][21];
int f[1<<20];

signed main(void){
    cin.tie(0)->sync_with_stdio(0);
    freopen("water.inp", "r", stdin);
    freopen("water.out", "w", stdout);
    cin >> n >> k;
    memset(f, 0x3f, sizeof(f));
    f[(1<<n)-1] = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> c[i][j];
        }
    }
    for(int i = 1; i <= n; i++) for(int j = 1; j <= n; j++){
        for(int l = 1; l <= n; l++){
            minimize(c[i][j], c[i][l] + c[l][j]);
        }
    }
    for(int msk = (1<<n) - 1; msk >= 1; msk--){
        int msk2 = msk;
        int i = 0;
        while(msk2){
            i = 31 - __builtin_clz(msk2);
            int msk3 = msk;
            int j = 0;
            while(msk3){
                j = 31 - __builtin_clz(msk3);
                if(j != i) minimize(f[(msk ^ (1<<i))], f[msk] + c[i+1][j+1]);
                msk3 ^= (1<<j);
            }
            msk2 ^= (1<<i);
        }
    }
    for(int msk = 0; msk < (1<<n); msk++){
        if(__builtin_popcount(msk) <= k){
            minimize(res, f[msk]);
        }
    }
    cout << res;
    return 0;
}
