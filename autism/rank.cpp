// Национална олимпиада - Национален кръг > D > 2024
// Author: H. Hristov

#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    set<ll> a;
    for (int i = 0; i < n; ++i) {
        ll x;
        cin >> x;
        a.insert(-x);
    }

    auto it = a.begin();
    advance(it, k);
    cout << -(*it);
}