#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>

using namespace std;

int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, c1 = 0, c2 = 0, c3 = 0, c4 = 0;
    cin >> n >> m;
    vector<int> a(n + 1, 0), b(n + 1, 0);
    while(m--) {
        int u, v;
        cin >> u >> v;
        ++a[u];
        ++b[v];
    }

    cout << '\n';
    for (int i = 1; i <= n; ++i) {
        if (i == 1) c2+=a[i];
        else if (a[i] != 0 && b[i] == 0) {
            c1 += a[i];
        }
        else if (a[i] != 0 && b[i] != 0) {
            c2 += a[i];
            c2 -= b[i];
        }

        cout << c1 << ' ' << c2 << '\n';
    }
}