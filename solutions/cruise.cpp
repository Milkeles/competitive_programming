// Author: H. Hristov
#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n, p, k;
        cin >> n >> p >> k;
        --p;

        vector<pair<int, int>> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i].first;
            a[i].second = i;
        }

        sort(a.begin(), a.end());

        int pos = 0;
        for (int i = 0; i < n; ++i) {
            if (a[i].second == p) {
                pos = i + 1;
                break;
            }
        }

        cout << max(pos, p + 1 - (n - 1 - k)) << '\n';
    }
    return 0;
}
