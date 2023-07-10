//lis
#include <bits/stdc++.h>
#define Vani "task"

using namespace std;

int a[100007], f[100007];

signed main(void){
    freopen(Vani".inp", "r", stdin);
    freopen(Vani".out", "w", stdout);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        f[i] = 1;
    }
    for(int i = 1; i <= n; i++){
        for(int j = i + 1; j <= n; j++){
            if(a[i] < a[j]) f[j] = max(f[i] + 1, f[j]);
        }
    }
    int res = 0;
    for(int i = 1; i <= n; i++){
        res = max(res, f[i]);
    }
    cout << res << '\n';
    return 0;
}
