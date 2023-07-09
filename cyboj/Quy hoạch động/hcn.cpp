#include <bits/stdc++.h>
using namespace std;

int xuligtloli(int m, int n){
    int dp[100][100];
    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            if(i == j){
                dp[i][j] = 1;
            }else{
                dp[i][j] = i * j;

                for(int k = 1; k <= i / 2; k++){
                    dp[i][j] = min(dp[i][j], dp[k][j] + dp[i - k][j]);
                }
                for(int k = 1; k <= j / 2; k++){
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[i][j - k]);
                }
            }
        }
    }

    return dp[m][n];
}

int main(){
    int m, n;
    cin >> m >> n;
    int res = xuligtloli(m, n);
    cout << res << '\n';
    return 0;
}
