#include <bits/stdc++.h>
using namespace std;

long long n;
long long a[1000007];
long long s[1000007][3];

int main(){
    cin.tie(0)->sync_with_stdio(0);

    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    memset(s, -0x3f, sizeof(s));
    s[0][0] = 0;
    s[1][1] = a[1];
    s[1][2] = 0;
    for(int i = 2; i <= n; i++){
        s[i][0] = max(s[i-2][2], s[i-1][1] + a[i]);
        s[i][1] = max(s[i-2][1] + a[i], s[i-1][2] + a[i]);
        s[i][2] = max(s[i-2][0], s[i-1][0]);
    }
    long long ok = max({s[n][0], s[n][1], s[n][2]});
    cout << ok << '\n';

    return 0;
}
