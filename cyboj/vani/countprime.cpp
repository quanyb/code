//countprime
#include <bits/stdc++.h>

using namespace std;

int countPrimes(int a, int b) {
    vector<bool> isPrime(b + 1, true);
    isPrime[0] = false;
    isPrime[1] = false;

    for (int i = 2; i * i <= b; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= b; j += i) {
                isPrime[j] = false;
            }
        }
    }

    int count = 0;
    for (int i = a; i <= b; i++) {
        if (isPrime[i]) {
            count++;
        }
    }

    return count;
}

int main() {
    freopen("countprime.inp", "r", stdin);
    freopen("countprime.out", "w", stdout);
    int a, b;

    cin >> a;

    cin >> b;

    int count = countPrimes(a, b);
    cout << count << '\n';

    return 0;
}
