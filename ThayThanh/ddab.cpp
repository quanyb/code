//dadb
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
#define f(i, a, b) for(int i = a; i < b; i++)
#define fd(i, a, b) for(int i = a; i > b; i--)
#define el '\n'

template<class T> inline bool maximize(T &r, const T &v) {return r < v ? r = v, 1 : 0;}
template<class T> inline bool minimize(T &r, const T &v) {return r > v ? r = v, 1 : 0;}

int n;
const int nm = 5000009;
int d = 0;
queue<int> q;

vector<int> unq(const vector<int> &a){
    unordered_map<int, int> m;
    for(int i : a){
        if(m.find(i) == m.end()){
            m[i] = 1;
            q.push(i);
        }else{
            m[i]++;

        }
    }
    vector<int> v;
    while(!q.empty()){
        int i = q.front();
        q.pop();
        if(m[i] == 1){
            v.push_back(i);
        }
    }
    return v;
}

signed main(void){

    if(fopen(Vani".inp", "r")){
        freopen(Vani".inp" ,"r", stdin);
        freopen(Vani".out", "w", stdout);
    }
    cin.tie(0)->sync_with_stdio(false);
    cin >> n;
    vector <int> a(n);
    f(i, 0, n){
        cin >> a[i];
    }
    vector<int> r = unq(a);
    for(int i : r){
        d++;
    }
    cout << d << '\n';
    for(int i : r){
        cout << i << " ";
    }
    return 0;
}
