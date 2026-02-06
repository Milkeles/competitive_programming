#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    short n, m; int shots = 0;
    cin >> n >> m;
    for(short i = 1; i < n; ++i) {
        for (short j = 1; j < m; ++j) {
            if (__gcd(i, j) == 1) ++shots;
        }
    }

    cout << shots + 2;
}