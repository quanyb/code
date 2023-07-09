//securities
#include <bits/stdc++.h>
#define ll long long
#define Vani"task"

using namespace std;

void gtloli(){
    int n;
       cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    int q;
    cin >> q;
    for(int i = 0; i < q; i++){
        int x;
        cin >> x;
        auto d = upper_bound(a.begin(), a.end(), x);

        if (d == a.begin()) {
            cout << -1 << '\n';
            continue;
        }

        d--;
        cout << *d << "\n";
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    //freopen(Vani".inp", "r", stdin);
    //freopen(Vani".out", "w", stdout);
    int t = 1;
    while (t--){
        
        gtloli();
    }
    return 0;
}
