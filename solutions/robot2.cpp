// Национална олимпиада - Областен кръг > C > 2011 > robot
// Author: H. Hristov
#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;

short ceilDiv(short a, short b) {
    short q = a /b;
    if ((a ^ b) > 0 && a % b != 0) ++q;
    return q;
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    short n, m, r, k;
    cin >> m >> n >> r >> k;
    
    short rRow = (r - 1) / n;
    short rCol = (r - 1) % n;
    
    int sum = 0;
    for (short i = 0; i < m; i++) {
        for (short j = 0; j < n; j++) {
            short dist = abs(i - rRow) + abs(j - rCol);
            if (dist <= k && (k - dist) % 2 == 0)
                sum += i * n + j + 1;
        }
    }
    cout << sum;
}