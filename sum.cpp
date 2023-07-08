#include <bits/stdc++.h>
#define Vani "task"

using namespace std;

int t[5007][5007];

int gtloli(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D){
    unordered_map<int, int> m;

    for (int a : A) {
        for (int b : B) {
            m[a + b]++;
        }
    }

    int res = 0;
    for(int c : C){
        for(int d : D){
            int tag = -(c + d);
            if(m.find(tag) != m.end()){
                res += m[tag];
            }
        }
    }

    return res;
}

int main(){
    freopen(Vani".inp", "r", stdin);
    freopen(Vani".out", "w", stdout);
    int n;
    cin >> n;
//    for(int i = 0; i < 3; i++){
//        for(int j = 0; j < n; j++){
//            cin >> t[i][j];
//        }
//    }

    vector<int> A(n);
    vector<int> B(n);
    vector<int> C(n);
    vector<int> D(n);

    for(int i = 0 ; i < n; i++){
        cin >> A[i];
        cin >> B[i];
        cin >> C[i];
        cin >> D[i];
    }

    int result = gtloli(A, B, C, D);
    cout << result << '\n';

    return 0;
}
