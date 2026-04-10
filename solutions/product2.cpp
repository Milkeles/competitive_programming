#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;

    vector<ll> d(n);
    for (int i = 0; i < n; ++i) {
        ll x; cin >> x;
        while(x >= 10) x /= 10;

        d[i] = x;
    }

    ll prod = 1;
    for(int i = 0; i < m; ++i) prod *= d[i];

    ll ans = prod;
    for (int i = m; i < n; ++i) {
        prod = prod / d[i - m] * d[i];
        ans = min(ans, prod);
    }

    cout << ans;
}