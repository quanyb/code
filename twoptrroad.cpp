//twoptrroad
#include <bits/stdc++.h>

#define ll long long
#define fi first
#define se second
#define Vani "task"

#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    freopen(Vani".inp", "r", stdin);
    freopen(Vani".out", "w", stdout);
    int n, a, b;
    cin >> n >> a >> b;
    vector<ii> v;
    for (int i = 0; i < n; ++i){
        int j, k;
        cin >> j >> k;
        v.push_back(ii(j, k));
    }
    sort(v.begin(), v.end());
    int j = -1, k = 1e9;
    int s[2] = {0};
    for(int i = 0; i < n; ++i){
        if(i > 0){
            --s[(v[i - 1].se) & 1];
        }
        while ((s[1] < a || s[0] < b) && j < n){
            ++s[(v[++j].se) & 1];
        }
        if(j == n){
            break;
        }
        k = min(k, v[j].fi - v[i].fi);
    }

    if(k == 1e9){
        cout << -1;
    }else{
        cout << k;
    }
    return 0;
}
