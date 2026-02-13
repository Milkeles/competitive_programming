// Национална олимпиада - Национален кръг > D > 2024
// Author: H. Hristov
#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int m, p;
    cin >> m >> p;
    if ((p & 1) == 0) {
        cout << 0;
        return 0;
    }

    ++m;
    vector<int> res;
    p = (p - 1)/2;
    for(int i = 1; i + p <= m; i<<=1){
        int n = i+p;
        if((i << 1) <= n)continue;
        res.push_back(n - 1);
    }

    if(res.empty()){
        cout<< 0;
        return 0;
    }

    cout << res.size() << '\n';
    for (int & x : res) cout << x << ' ';

    return 0;
}