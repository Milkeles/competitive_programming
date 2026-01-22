// Author: H. Hristov
#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll getPr(ll a, ll b) {
    if (b <= a) return b - a;
    else return ((b - a) * 2);
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll a, b, c, n;
    cin >> a >> b >> c >> n;

    ll lo = min(a, min(b, c)), hi = max(a, max(b,c)) + (n >> 1);

    while (hi - lo > 1) {
        ll mid = (hi + lo) >> 1;
        ll price = 0;

        price += getPr(a, mid);
        price += getPr(b, mid);
        price += getPr(c, mid);
        
        // cout << mid << '\n';
        if (price <= n)
            lo = mid;
        else
            hi = mid;
    }

    cout << lo;
    return 0;
}