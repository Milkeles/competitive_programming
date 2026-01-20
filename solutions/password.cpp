//Author: H. Hristov
#pragma GCC optimize("O3,unroll-loops,Ofast,avx2,fast-math")
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    string n;
    int k;
    cin >> n >> k;
    
    string res = "";
    
    for (char c : n) {
        while (k > 0 && !res.empty() && res.back() < c) {
            res.pop_back();
            --k;
        }
        res.push_back(c);
    }
    
    while (k > 0 && !res.empty()) {
        res.pop_back();
        --k;
    }
    
    int start = res.find_first_not_of('0');
    if (start == string::npos) cout << '0';
    else cout << res.substr(start);
    
    return 0;
}