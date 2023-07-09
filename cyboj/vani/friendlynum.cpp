#include <bits/stdc++.h>

using namespace std;

int loli(int u)
{
    int umoi = 0, i = 0;
    while(u != 0){
        umoi += u % 10;
        umoi *= 10;
        u /= 10;
        i++;
    }
    umoi /= 10;
    return umoi;
}

int main()
{
    freopen("friendlynum.inp" , "r" , stdin);
    freopen("friendlynum.out" , "w" , stdout);
    int a, b; cin >> a >> b;
    int dem = 0;
    for (int i = a; i <= b; i++)
        if (__gcd(i, loli(i)) == 1)
            dem++;
    cout << dem;
    return 0;
}
