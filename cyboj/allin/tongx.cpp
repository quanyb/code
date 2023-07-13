//Code by quntt <3
#include <bits/stdc++.h>
#define nmax 1000007

using namespace std;

int n, k, a[nmax],b[nmax];
int d=0;
vector <int> v;
map <int, int> hm;
map <int, int>:: iterator it;

void xuli(){
    int s=0;
    for(int i = 1; i <= n; i++){
        if(a[i] + a[i+1] == k){
            d++;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    freopen("tongx.inp", "r", stdin);
    freopen("tongx.out", "w", stdout);
    cin >> n >> k;
    for(int i=1; i <= n; i++)
        cin >> a[i];
    xuli();
    cout << d;
    return 0;
}
