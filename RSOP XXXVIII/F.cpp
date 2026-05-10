// RSOP XXXVIII > F
// Author: Retarded piece of shit
#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>

#define FOR(i, a, b) for(int i = (a); i <= (b); ++i)
using ll = long long;
using ull = unsigned long long;

using namespace std;

// V1 - from competition
/* O(n * m * min(n, m)^3)
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--) {
        int n, m, s, mx = 0;
        cin >> n >> m;
        s = min(n, m);
        vector<vector<char>> a(n, vector<char>(m));
        FOR(i, 0, n - 1) FOR(j, 0, m-1) cin >> a[i][j];

        while (s > 0 && !mx) {
            for (int i = 0; i + s <= n && !mx; ++i) {
                for (int j = 0; j + s <= m && !mx; ++j) {
                    bool valid = true;
                    for (int k = i; k < i + s && valid; ++k) {
                        for (int l = j; l < j + s && valid; ++l) {
                            if (a[k][l] == '0') valid = false;
                        }
                    }
                    if (valid) mx = s;
                }
            }
            --s;
        }
        cout << mx << '\n';
    }
}*/

// O(n * m * min(n, m)) ~= 10^9 ops ~= 1s
/*int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--) {
        int n, m, s, mx = 0;
        cin >> n >> m;
        s = min(n, m);
        vector<vector<char>> a(n, vector<char>(m));
        FOR(i, 0, n - 1) FOR(j, 0, m-1) cin >> a[i][j];

        while (s > 0 && !mx) {
            vector<int> pref(m, 0);
            FOR(i, 0, s - 1) FOR(j, 0, m - 1)
                if (a[i][j] == '0') ++pref[j];

            for (int i = 0; i + s <= n && !mx; ++i) {
                if (i > 0) {
                    for (int j = 0; j < m; ++j) {
                        if (a[i - 1][j]     == '0') --pref[j];
                        if (a[i + s - 1][j] == '0') ++pref[j];
                    }
                }

                int win = 0;
                FOR(j, 0, s - 1) win += pref[j];
                if (win == 0) { mx = s; break; }

                for (int j = 1; j + s <= m; ++j) {
                    win += pref[j + s - 1] - pref[j - 1];
                    if (win == 0) { mx = s; break; }
                }
            }
            --s;
        }
        cout << mx << '\n';
    }
}*/

// V3
/*
const int MAXM = 1000;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n, m, s, mx = 0;
        cin >> n >> m;
        s = min(n, m);
        vector<bitset<MAXM>> a(n);
        FOR(i, 0, n-1) {
            FOR(j, 0, m-1) {
                char c;
                cin >> c;
                if (c == '0') a[i].set(j);
            }
        }

        while(s > 0 && !mx) {
            bitset<MAXM> base;
            for (int k = 0; k < s; ++k) base.set(k);

            bitset<MAXM> col;
            for (int k = 0; k < s; ++k) col |= a[k];

            for (int i = 0; i + s <= n && !mx; ++i) {
                if (i > 0) {
                    col.reset();
                    for (int k = i; k < i + s; ++k) col |= a[k];
                }
                bitset<MAXM> mask = base;
                for (int j = 0; j + s <= m && !mx; ++j) {
                    if ((col & mask).none()) mx = s;
                    mask <<= 1;
                }
            }
            --s;
        }
        cout << mx << '\n';
    }
}*/

// V4 - interesting. 
// O(n * m) ~= 0.01s
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, m, mx = 0;
        cin >> n >> m;
        vector<vector<int>> dp(n, vector<int>(m, 0));
        FOR(i, 0, n - 1) {
            FOR(j, 0, m - 1) {
                char c;
                cin >> c;
                if (c == '1') {
                    if (i == 0 || j == 0) dp[i][j] = 1;
                    else dp[i][j] = min(dp[i-1][j], min(dp[i][j-1], dp[i-1][j-1])) + 1;
                    if (dp[i][j] > mx) mx = dp[i][j];
                }
            }
        }
        cout << mx << '\n';
    }
}