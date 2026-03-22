// Национална олимпиада - Общински кръг > D > 2024 > product
// Author: H. Hristov
#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll cntPow(ll x, ll p) {
    ll cnt = 0;
    for (ll pk = p; pk <= x; pk *= p)
        cnt += x / pk;

    return cnt;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll a, b;
    cin >> a >> b;

    ll cnt2 = cntPow(b, 2) - cntPow(a - 1, 2);
    ll cnt5 = cntPow(b, 5) - cntPow(a - 1, 5);
    cout << min(cnt2, cnt5);
}