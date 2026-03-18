// Национална олимпиада - Национален кръг > E > 2026 > guess
// Author: H. Hristov
#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    ll n;
    vector<int> digits;
    int s = 0;
    cin >> n;
    bool hasZero = false;

    while (n > 0) {
        int d = n % 10;
        digits.push_back(d);
        s += d;
        if(d == 0) hasZero = true;
        n /= 10;
    }

    if (!hasZero || s % 3 != 0) {
        cout << -1;
        return 0;
    }

    sort(digits.begin(), digits.end(), greater<int>());

    for (int d : digits) {
        cout << d;
    }

    return 0;
}
