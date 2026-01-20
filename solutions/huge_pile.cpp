#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    short t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        int low = n, high = n, cnt = 0;
        while (high != 1) {
            if (low == m || high == m) break;
            ++cnt;
            low >>= 1;
            high = (high >> 1) + (high & 1);

        }

        if (low == m || high == m) cout << cnt << '\n';
        else cout << -1 << '\n';

    }
    return 0;
}