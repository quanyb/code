//wood
#include <bits/stdc++.h>
#define Vani "wood"
using namespace std;

void qs(long a[], long left,long right)
{
    long i, j, x;
    i = left; j = right;
    x = a[(left+right)/2];
    do{
    while(a[i]<x && i<right) i++;
    while(a[j]>x && j>left) j--;
        if(i<=j){
            swap(a[i], a[j]);
            i++; j--;
        }
    }while (i<=j);
    if(left<j) qs(a,left,j);
    if(i<right) qs(a,i,right);
}


int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    freopen(Vani".inp", "r", stdin);
    freopen(Vani".out", "w", stdout);
	long n, m, i;
	long *a;
	long t;
	long long T=0,s=0;
	cin >> n >> m;
	a = new long [n+5];
	for(i = 1; i <= n; i++)
	{
		cin >> a[i];
		T+=a[i];
	}
	qs(a,1,n);
	a[0]=0;
	t=n+1;
	for(i = 1; i <= n; i++)
	{
 		s += (a[i] - a[i-1]) * (t-i);
		if(T-s<m) break;
	}
	s-=(a[i]-a[i-1])*(t-i);
	long K=(T-s-m)/(t-i);
	cout << a[i-1] + K;
	return 0;
}
