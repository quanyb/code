//sumpair
#include <bits/stdc++.h>
#define Vani "task"
#define ll long long

using namespace std;

ll a[1000007];

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    freopen(Vani".inp", "r", stdin);
    freopen(Vani".out", "w", stdout);
    ll n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    ll q;
    cin >> q;
    while(q--){
        ll x;
        cin >> x;
        ll i = 1, j = n, res = 0;
        while(i < j){
            if(a[i] + a[j] <= x){
                    res += max(1ll * 0, j - i);
                    ++i;

            }else --j;

        }
        cout << res << '\n';
    }

    return 0;
}
