// RSOP XXXVIII > I
// Author: H. Hristov
#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>

#define FOR(i, a, b) for(int i = (a); i <= (b); ++i)
using ll = long long;
using ull = unsigned long long;

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<ll> a(n);
        ll lo = 0, hi = 0;
        FOR(i, 0, n - 1) {
            cin >> a[i];
            if (a[i] > lo) lo = a[i];
            hi += a[i];
        }

        while (lo < hi) {
            ll mid = lo + (hi - lo) / 2;
            int trucks = 1;
            ll cur = 0;
            FOR(i, 0, n - 1) {
                if (cur + a[i] > mid) { ++trucks; cur = a[i]; }
                else cur += a[i];
            }
            if (trucks <= k) hi = mid;
            else lo = mid + 1;
        }

        cout << lo << '\n';
    }
}