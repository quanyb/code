#include <bits/stdc++.h>
#define Vani "task"

#define MAX 1000001
#define MASK(k) (1LL << (k))
#define BIT(x, i) (((x) >> (i)) & 1)
#define __builtin_popcount __builtin_popcountll
#define __builtin_ctz __builtin_ctzll
#define ll long long
#define vi vector<int>
#define mii map<int, int>
#define pii pair<int, int>
#define pb push_back
#define fi first
#define se second

template<class X, class Y>
    bool minimize(X &x, const Y &y) {
        X eps = 1e-9;
        if (x > y + eps) {
            x = y;
            return true;
        } else return false;
    }
template<class X, class Y>
    bool maximize(X &x, const Y &y) {
        X eps = 1e-9;
        if (x + eps < y) {
            x = y;
            return true;
        } else return false;
    }
template<class T>
    T Abs(const T &x) {
        return (x < 0 ? -x : x);
    }
const int INF = 1e9 + 7;
const ll oo = 1e18;
using namespace std;
double a[MAX], b[MAX];
int n;
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    freopen(Vani".inp", "r", stdin);
    freopen(Vani".out", "w", stdout);
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i] >> b[i];
        a[i]-=1.0, b[i]-=1.0;
    }

    sort(a, a + n, greater<double>());
    sort(b, b + n, greater<double>());
    int i = 0, j = 0;
    double ans = 0, suma = 0, sumb = 0;
    while(i < n){
        suma += a[i];
        i++;
        while(j < n && min(suma - j, sumb - i) < min(suma - (j + 1), sumb + b[j] - i)){
            sumb += b[j];
            j++;
        }
        maximize(ans, min(suma - j, sumb - i));
    }
    cout << fixed << setprecision(4) << ans;
    return 0;
}
