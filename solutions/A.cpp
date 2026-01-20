// Author: H. Hristov
#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    short t;
    cin >> t;
    while (t--) {
        int n, m, h;
        cin >> n >> m >> h;
        vector<int> a(n);
        for (int & num : a) cin >> num;
        vector<int> b(n, 0);
        vector<int> c(n, -1);
        int r = 0;
        while(m--) {
            int ind, val;
            cin >> ind >> val;
            --ind;
            if (c[ind] != r) {
                c[ind] = r;
                b[ind] = 0;
            }
            b[ind] += val;
            if (a[ind] + b[ind] > h) ++r;
        }
        for (int i = 0; i < n; ++i) {
            int res = a[i] + (c[i] == r ? b[i] : 0);
            cout << res << ' ';
        }
        cout << '\n';
    }
    return 0;
}