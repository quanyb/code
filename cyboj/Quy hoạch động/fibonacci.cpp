#include <bits/stdc++.h>
using namespace std;

long long f[1000007];

long long fibo(int n, long long modulo){
    f[n + 1];
    f[0] = 0;
    f[1] = 1;

    for(int i = 2; i <= n; ++i){
        f[i] = (f[i - 1] + f[i - 2]) % modulo;
    }

    return f[n];
}

int main(){
    int n;
    cin >> n;
    long long fibonacci = fibo(n + 1, 1770136969);
    cout << fibonacci << '\n';

    return 0;
}
