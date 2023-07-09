//thangcap
#include<bits/stdc++.h>
#define Vani "task"

using namespace std;

typedef long long ll;
int n, a[500005];

int binarySearch(int arr[], int n, int x) {
   int l = 0,r = n;
   if (x > arr[n]) return n;
   while(r >= l)
   {
       int mid = (l + r) / 2;
       if (arr[mid] == x || ((arr[mid]) < x && (arr[mid + 1] > x)))
       {
           int j = mid;
           while ((arr[j + 1] == x || ((arr[j + 1]) < x && (arr[j + 2] > x)))) j++;
           return j;
       }
       if(arr[mid] > x)
           r = mid - 1;
       if(arr[mid] < x)
           l = mid + 1;
   }
   return 0;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen(Vani".inp","r",stdin);
    freopen(Vani".out","w",stdout);
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    int t, x, y;
    cin >> t;
    for(int i = 1;i <= t; i++)
    {
        cin >> x >> y;
        int s = x + y;
        int res = binarySearch(a, n, x);
        int res1 = binarySearch(a, n, s);
        cout << res1 - res << "\n";
    }
    return 0;
}
