// Author: H. Hristov
#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    short t;
    cin >> t;
    while(t--) {
        int n; ll x;
        cin >> n >> x;
        ll res = LLONG_MIN, cur = 0;
        for (int i = 0; i < n; ++i) {
            ll a, b, c; 
            cin >> a >> b >> c;
            cur += (b - 1) * a;
            ll cur2 = a * b - c;
            if (cur2 > res) res = cur2;
        }

        if (cur >= x) {
            cout << 0 << '\n';
            continue;
        }
        if (res <= 0) {
            cout << -1 << '\n';
            continue;
        }
        // cout << cur << '\n';
        cout << ((x - cur) + res - 1) / res << '\n';

    }
    return 0;

}
