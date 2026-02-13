// Национална олимпиада - Национален кръг > D > 2025
// Author: H. Hristov
#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m, x;
    cin >> n >> m;
    
    vector<bool> seen;
    int q = m + 1;
    
    while(n--) {
        cin >> x;
        if (x > m) {
            int idx = x - m - 1;
            
            if (idx >= seen.size()) {
                seen.resize(idx + 1, false);
            }
            
            seen[idx] = true;

            while(q - m - 1 < seen.size() && seen[q - m - 1]) {
                ++q;
            }
        }
    }
    
    cout << q;
}