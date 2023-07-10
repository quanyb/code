//binsearch
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

int n, q;
const int nm = 500009;
int a[nm];

int tknp(int u, int x){
    int l = 1, r = u, mid;
    while(l <= r){
        mid = (l + r) / 2;
        if(a[mid] == x){
            return mid;
        }
        if(a[mid] < x){
            l= mid + 1;
        }else{
            r = mid - 1;
        }
    }
    return -1;
}

void bs(int u, int v){
    int res = tknp(u, v);
    cout << res << '\n';   
}

signed main(void){

    if(fopen(Vani".inp", "r")){
        freopen(Vani".inp" ,"r", stdin);
        freopen(Vani".out", "w", stdout);
    }
    cin.tie(0)->sync_with_stdio(false);
    int n, q;
    cin >> n >> q;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    while(q--){
        int x;
        cin >> x;
        bs(n, x);
    }
    return 0;
}
