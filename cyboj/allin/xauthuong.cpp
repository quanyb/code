#include <bits/stdc++.h>
#include <string.h>

using namespace std;

string s;
int d=0;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    freopen("xauthuong.inp", "r", stdin);
    freopen("xauthuong.out", "w", stdout);
    getline(cin, s);
    for(int i = 0; i <= s.size()-1; i++){
        if(s[i] >= 'A' && s[i] <= 'Z'){
            s[i] = s[i] + 32;
        }
    }
    for(int i = 0; i <= s.size()-1; i++)
        cout << s[i];
    return 0;
}
