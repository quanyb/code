//numorder
#include <bits/stdc++.h>
#define Vani "task"

using namespace std;

long long n,m,k;

int cal(long long val){
    long long pos=0;
    for(long long i = 1; i <= n; i++){
        pos += min((long long)sqrt(val - i * i),m);
        if(val < i * i) break;
    }
    return pos;
}

long long ps(long long l,long long r,int pos){
    long long m;
    while(l <= r){
        m = (l + r) / 2;
        if (cal(m) < k) l = m + 1;
        else r = m - 1;
    }
    return l;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    freopen(Vani".inp", "r", stdin);
    freopen(Vani".out", "w", stdout);
    cin >> m >> n >> k;
    if(m < n) swap(m, n);
    cout << ps(1, m * m + n * n, k);
    return 0;
}
