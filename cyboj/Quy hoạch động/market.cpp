#include <bits/stdc++.h>
#define nmax 1000007
#define ll long long
#define f(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)
using namespace std;
ll n,m;
ll c[nmax],a[nmax], f[nmax];
void minimize(ll &x, ll y)
{
    if(x > y) x=y;
}
void xl()
{
    f(i,1,n) cin>>a[i];
    f(i,1,m) cin>>c[i];
    fd(i,m-1,1) c[i]=min(c[i],c[i+1]);
    sort(a+1,a+n+1);
    memset(f, 0x3f, sizeof f);
    f[0]=0;
    f(st,0,n-1)
        f(ed,0,st)
            minimize(f[st+1],f[ed]+c[a[st+1]-a[ed+1]+1]);
    cout<<f[n];
}
int main()
{
    ios_base::sync_with_stdio(false);   cin.tie(NULL);
    freopen("MARKET.inp","r",stdin);
    freopen("MARKET.out","w",stdout);
    cin >> n >> m;
    xl();
    return 0;
}
