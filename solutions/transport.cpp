// Национална олимпиада - Национален кръг > E > 2009 > transport
// Author: H. Hristov
#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n, m, res = 0, sum = 0;
    cin >> n;
    vector<ll> arr(n);
    for(ll & x : arr) cin >> x;
    cin >> m;
    for (ll & x : arr) {
        sum += x;
        if (sum > m) {
            ++res;
            sum = x;
        }
    }
    if (sum != 0) ++ res;
    cout << res;
}