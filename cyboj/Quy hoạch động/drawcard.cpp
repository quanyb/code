#include <bits/stdc++.h>

using namespace std;

int main(){
    freopen("DRAWCARD.inp", "r", stdin);
    freopen("DRAWCARD.out", "w", stdout);
    long long n;
    cin >> n;
    vector<long long> cards(n);
    for (int i = 0; i < n; i++) {
        cin >> cards[i];
    }

    vector<vector<long long>> dp(n, vector<long long>(n, 0));

    for (int i = 2; i <= n - 2; i++) {
        for (int j = 0; j <= n - 2; j++) {
            long long minCost = LLONG_MAX;
            for (int k = j + 1; k <= j + i - 1; k++) {
                long long cost = 1ll * cards[j] * cards[k] * cards[j + i] + dp[k - j][j] + dp[j + i - k][k];
                minCost = min(minCost, cost);
            }
            dp[i][j] = minCost;
        }
    }

    long long minCost = LLONG_MAX;
    for (int k = 1; k <= n - 2; k++) {
        long long cost = 1ll * cards[0] * cards[k] * cards[n - 1] + dp[k][0] + dp[n - 1 - k][k];
        minCost = min(minCost, cost);
    }

    cout << minCost << endl;

    return 0;
}
