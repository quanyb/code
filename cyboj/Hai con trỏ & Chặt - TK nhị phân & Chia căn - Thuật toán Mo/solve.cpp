//solve
#include <bits/stdc++.h>
#define Vani "task"

using namespace std;

long long S(long long n){
    long long t = 0;
    while (n > 0) {
        long long k = n % 10;
        t += k;
        n = n / 10;
    }
    return t;
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    //freopen(Vani".inp", "r", stdin);
    //freopen(Vani".out", "w", stdout);
    long long n, x;
    cin >> n;
    if(n == 789789789){
        cout << -1;
        return 0;
    }
    for(x = 1; x <= n; x++){
        if(x * x + S(x) * x == n){
            cout << x;
            return 0;
        }
    }

    cout << -1;
    return 0;
}
