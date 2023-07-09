//triplelow
#include <bits/stdc++.h>
#define Vani "task"
#define ll long long

using namespace std;

ll a[1000007];

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    freopen(Vani".inp", "r", stdin);
    freopen(Vani".out", "w", stdout);
    ll n, x;
    cin >> n >> x;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a , a + n);
    ll res = 0;
    for(int i = 0; i < n - 2; i++){
        ll l = i + 1;
        ll r = n - 1;
        while(l < r){
            if(a[i] + a[l] + a[r] <= x){
                res += max(1ll * 1, r - l);
                ++l;
            }else --r;
        }
    }
    cout << res << '\n';
    return 0;
}
