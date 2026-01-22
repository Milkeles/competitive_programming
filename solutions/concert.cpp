//Author: H. Hristov
#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector<int> t(k);
    for (int &x : t) cin >> x;
    ll lo = 0;
    ll hi = 1LL * n * (*max_element(t.begin(), t.end()));

    while (lo < hi) {
        ll mid = (lo + hi) / 2;
        ll cnt = 0;

        for (int & x : t) {
            cnt += mid / x;
            if (cnt >= n) break;
        }

        if (cnt >= n)
            hi = mid;
        else
            lo = mid + 1;
    }
    cout << lo;
}
