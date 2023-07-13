#include <bits/stdc++.h>
#include <string.h>

using namespace std;

string s;
int d=0;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    freopen("demkta.inp", "r", stdin);
    freopen("demkta.out", "w", stdout);
    getline(cin, s);
    for(int i = 0; i <= s.size()-1; i++){
        if(s[i] == 'a' || s[i] == 'A'){
            d++;
        }
    }
    cout << d;
    return 0;
}
