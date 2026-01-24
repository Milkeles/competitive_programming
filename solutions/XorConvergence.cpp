#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        if ((n & (n - 1)) == 0) {
            cout << "-1\n";
            continue;
        }

        auto get_msb = [](int n) {
            int msb = 1;
            while ((msb << 1) <= n) msb <<= 1;
            return msb;
        };

        vector<int> p(n + 1);
        vector<bool> used(n + 1, false);
        vector<int> active;

        int root = (n % 2 != 0) ? n : get_msb(n);
        p[n] = root;
        used[root] = true;
        active.push_back(root);

        for (int i = n - 1; i >= 1; --i) {
            int best_val = -1;
            for (int u : active) {
                int v = u ^ i;
                if (v >= 1 && v <= n && !used[v]) {
                    best_val = v;
                    break;
                }
            }
            p[i] = best_val;
            used[best_val] = true;
            active.push_back(best_val);
        }

        for (int i = 1; i <= n; ++i)
            cout << p[i] << (i == n ? "\n" : " ");
    }
}