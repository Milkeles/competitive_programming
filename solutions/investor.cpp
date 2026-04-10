// Investor
#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n, m;
    cin >> n >> m;
    vector<ll> a(n);
    for (ll & x : a) cin >> x;

    ll sum = 0, l = 0, blen = 0, bstart = 0;
    for (ll r = 0; r < n; ++r) {
        sum += a[r];
        while(sum > m && l <= r) {
            sum -= a[l];
            ++l;
        }

        if (r - l + 1 > blen) {
            blen = r - l + 1;
            bstart = l + 1;
        }
    }

    cout << blen << ' ' << bstart;
}