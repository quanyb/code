#include <bits/stdc++.h>
#define nmax 100007
#define f(i, a, b) for(int i = a; i <= b; i++)

using namespace std;

int n;
int a[nmax];
vector <int> v;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    freopen("ptmin.inp","r",stdin);
    freopen("ptmin.out","w",stdout);
    cin >> n;
    f(i, 1, n){
        cin >> a[i];
        v.push_back(a[i]);
    }
    sort(v.begin(), v.end());
    cout << v[0];
    return 0;
}
