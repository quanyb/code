#include <bits/stdc++.h>

using namespace std;

#define task "WTRIPLE"
#define endl ('\n')
#define MASK(i) (1LL << (i))         // mask cuối cùng cộng 1 //11111 + 1 = 100000
#define BIT(x, i) (((x) >> (i)) & 1) // bit thứ i của mask x
#define COMPLEMENT(x, num_bit) ((MASK((num_bit)) - 1)^(x)) // phần bù của mask x
#define MAX (int)1e5 + 7
#define MOD ((int)1e9 + 7)

template<class T> inline bool maximize(T &r, const T &v) {return r < v ? r = v, 1 : 0;}
template<class T> inline bool minimize(T &r, const T &v) {return r > v ? r = v, 1 : 0;}

int highestOneBit(int n){
    n |= (n >> 1);
    n |= (n >> 2);
    n |= (n >> 4);
    n |= (n >> 8);
    n |= (n >> 16);
    return n - (n >> 1);
}

long long add(long long x, long long y) {
    x += y;
    if (x >= MOD) x -= MOD;
    return x;
}

long long sub(long long x, long long y) {
    x -= y;
    if (x < 0) x += MOD;
    return x;
}

long long power(long long a, long long n){
    long long res = 1;
    a %= MOD;
    while (n > 0){
        if (n & 1){
            res = (res * a) % MOD;
        }
        n /= 2;
        a = (a * a) % MOD;
    }
    return (res + MOD) % MOD;
}

long long multi(long long a, long long b){
    return ((a % MOD) * (b % MOD)) % MOD;
}

long long n, m, q;
long long a[MAX], b[MAX], c[MAX];
long long prefix_a[MAX], prefix_c[MAX];
long long res = 0;

void algorithm(){
    cin >> n >> m >> q;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
    }
    for (int i = 1; i <= m; ++i){
        cin >> b[i];
    }
    for (int i = 1; i <= q; ++i){
        cin >> c[i];
    }
    sort(a + 1, a + n + 1, greater<long long>());
    sort(b + 1, b + m + 1, greater<long long>());
    sort(c + 1, c + q + 1, greater<long long>());

    for (int i = 1; i <= n; ++i){
        prefix_a[i] = add(prefix_a[i - 1], a[i]);
        // cout << prefix_a[i] << " ";
    }
    cout << endl;
    for (int i = 1; i <= q; ++i){
        prefix_c[i] = add(prefix_c[i - 1], c[i]);
        // cout << prefix_c[i] << " ";
    }

    long long point_a = 1;
    long long point_c = 1;
    // cout << power(22, 2);
    for (int i = 1; i <= m; ++i){
        while (a[point_a] > b[i] && point_a <= n){
            ++point_a;
        }
        while (c[point_c] > b[i] && point_c <= q){
            ++point_c;
        }

        if (point_c > q || point_a > n) break;
        res = add(res, add( add(multi(power(b[i], 2), multi(n - point_a + 1, q - point_c + 1)),
        multi(sub(prefix_c[q], prefix_c[point_c - 1]), sub(prefix_a[n], prefix_a[point_a - 1]))),
        multi(
            add(
                multi(q - point_c + 1, sub(prefix_a[n], prefix_a[point_a - 1])),
                multi(n - point_a + 1, sub(prefix_c[q], prefix_c[point_c - 1]))), b[i])));
    }
    cout << res;
}

int main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    if (fopen(task ".inp", "r")) {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }

    algorithm();
    return 0;
}
