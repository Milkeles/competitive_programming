// Национална олимпиада / Национален кръг / D / 2021 / major
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
        int n;
        cin >> n;

        vector<int> a(n), b(n);
        for(int & x : a) cin >> x;
        for(int & x : b) cin >> x;

        int half = (n + 1) / 2;

        unordered_map<int, int> cntA, cntB;
        for (int i = 0; i < n; i++) {
            cntA[a[i]]++;
            if (a[i] != b[i]) {
                cntB[b[i]]++;
            }
        }

        int ans = INT_MAX;
        for (auto &[x, A] : cntA) {
            int B = cntB[x];
            if (A + B >= half) {
                ans = min(ans, max(0, half - A));
            }
        }

        for (auto &[x, B] : cntB) {
            if (!cntA.count(x)) {
                int A = 0;
                if (A + B >= half) {
                    ans = min(ans, half);
                }
            }
        }

        if (ans == INT_MAX) ans = -1;
        cout << ans << '\n';
    }

    return 0;
}