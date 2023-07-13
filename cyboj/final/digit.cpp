//digit
#include <bits/stdc++.h>
#define Vani "task"

using namespace std;

#define pb push_back
#define ii pair<int, int>
#define fi first
#define se second
#define ll long long
#define sortin(a, n) sort(a, a + n)
#define all(a) a.begin(), a.end()
#define f(i, a, b) for(int i = a; i <= b; i++)
#define fd(i, a, b) for(int i = a; i >= b; i--)
#define el '\n'
using namespace std;

template<class INT> INT maximize (INT &a, const INT &b){if(a < b){a = b;}return a;}
template<class INT> INT minimize (INT &a, const INT &b){if(a > b){a = b;}return a;}

const int nmax = (int)24 +7;
const ll oo = (ll)1e18 + 7;

string s;
int n, k;

string daokomi(const string& str)
{
    string res = str;
    reverse(res.begin(), res.end());
    return res;
}


void inkomi(){
//    ll sizekomi = kokomi(x);
//
//    //cout << sizekomi << el;
//    ll temp = 0, d = 0;
//    for(ll i = 1; i <= ka; i++){
//        d++;
//        val[i].fi = i;
//        if(d == sizekomi){
//            temp++;
//            d = 0;
//        }
//        val[i + 1].se = temp;
//        if(temp == ka) break;
//
//    }
//    int res = 0;
//    for(int i = 1; i <= ka; i++){
//        cout << val[i].fi << " " << val[i].se << " ";
//        int res = val[i].fi - sizekomi * val[i].se;
//        cout << res << '\n';
//    }
//    cout << res;
//    ll res = val[ka].fi - sizekomi * val[ka].se;
//    if(res - 1)
//    cout << x[res - 1];
    string str = s + daokomi(s);
    int pos = k % (str.size());
    ll length = str.size() * (ll)pow(2, n);
    if(pos == 0) pos = str.size();
    if(length < (ll)k) cout << -1;
    else cout << str[pos-1];
}

int main()
{
    cin.tie(0) -> sync_with_stdio(false);
    if(fopen(Vani".inp","r")){
        freopen(Vani".inp","r",stdin);
        freopen(Vani".out","w",stdout);
    }
    cin >> s;
    cin >> n >> k;
    inkomi();
    return 0;
}
