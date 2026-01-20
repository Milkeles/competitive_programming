// Author: H. Hristov
#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    short t;
    cin >> t;
    while(t--) {
        int n, m, k;
        cin >> n >> m >> k;

        vector<int> a(n), b(m), ml(k + 1), mr(k + 1), dieAt(k+2);
        for (int &num : a) cin >> num;
        for (int &num : b) cin >> num;
        string s;
        cin >> s;

        stable_sort(a.begin(), a.end());
        stable_sort(b.begin(), b.end());

        int l = 0, r = 0;
        for (int i = 1; i <= k; ++i) {
            ((s[i-1] == 'L') ? (++l, --r) : (++r, --l));
            ml[i] = max(ml[i-1], l);
            mr[i] = max(mr[i-1], r);
        }

        for (int i = 0; i < n; ++i) {
            int lo = 1, hi = k, ans = -1;
            while (lo <= hi) {
                int mid = (lo + hi) >> 1;
                bool dead = false;

                int L = a[i] - ml[mid];
                int R = a[i] + mr[mid];

                auto it = lower_bound(b.begin(), b.end(), L);
                if (it != b.end() && *it <= R) dead = true;
                if (dead) {
                    ans = mid;
                    hi = mid - 1;
                } else {
                    lo = mid + 1;
                }
            }
            if (ans != -1) ++dieAt[ans];
        }

        int alive = n;
        for (int i = 1; i <= k; ++i) {
            alive -= dieAt[i];
            cout << alive << " \n"[i==k];
        }
    }
}
