// Author: H. Hristov
#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll d, a, b, cnt2 = 0, cnt5 = 0;
    cin >> d >> a >> b;
    while(a % d != 0) ++a;
    for (a; a <= b; a += d) {
        ll d = a;
        while(d % 2 == 0) {
            d >>= 1;
            ++cnt2;
        }
        while(d % 5 == 0) {
            d /= 5;
            ++cnt5;
        }
    }

    cout << min(cnt2, cnt5);
}