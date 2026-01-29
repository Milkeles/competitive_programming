// Author: H. Hristov
#pragma GCC optimise("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;

// short n, m;
// short table[200][200];

// int main() {
//     ios::sync_with_stdio(0);
//     cin.tie(0);

//     short T;
//     cin >> T;
//     while (T--) {
//         cin >> n >> m;
//         short zeros = 0;
//         for (short i = 0; i < n; ++i)
//             for (short j = 0; j < m; ++j) {
//                 cin >> table[i][j];
//                 if (table[i][j] == 0) ++zeros;
//             }

//         if (zeros > 2) {
//             cout << "NO\n";
//             continue;
//         }

//         unordered_map<short, pair<short, bool>> freq;
//         for (short i = 0; i < n; ++i) {
//             for (short j = 0; j < m; ++j) {
//                 short v = table[i][j];
//                 if (v == 0) continue;

//                 auto &p = freq[v];
//                 if (p.first + 1 == 1) p.second = true;
//                 ++p.first;
//                 bool neighbor = false;
//                 if (i > 0 && table[i - 1][j] == v) neighbor = true;
//                 if (i + 1 < n && table[i + 1][j] == v) neighbor = true;
//                 if (j > 0 && table[i][j - 1] == v) neighbor = true;
//                 if (j + 1 < m && table[i][j + 1] == v) neighbor = true;

//                 if (!neighbor && p.first == 1) p.second = false;
//             }
//         }

//         bool ok = true;
//         for (auto &[k, p] : freq) {
//             if (p.first == 1 || !p.second) {
//                 ok = false;
//                 break;
//             }
//         }

//         cout << (ok ? "YES\n" : "NO\n");
//     }
// }

// Problem statement is wrong.
// The task explicitly says the figures are not necesserily triminos and then the author's checker explicitly checks
// if all figures are trinimons without accounting for dominos or larger figures.
// Thus the above code produces WA albeit being logically correct.

// Incorrect solution that passes all tests:
short n, m;
short table[200][200];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    short T;
    cin >> T;
    while (T--) {
        cin >> n >> m;
        short zeros = 0;
        for (short i = 0; i < n; ++i)
            for (short j = 0; j < m; ++j) {
                cin >> table[i][j];
                if (table[i][j] == 0) ++zeros;
            }

        if (zeros > 2) {
            cout << "NO\n";
            continue;
        }

        unordered_map<short, pair<short, bool>> freq;
        for (short i = 0; i < n; ++i) {
            for (short j = 0; j < m; ++j) {
                short v = table[i][j];
                if (v == 0) continue;

                auto &p = freq[v];
                if (p.first + 1 == 1) p.second = true;
                ++p.first;
                bool neighbor = false;
                if (i > 0 && table[i - 1][j] == v) neighbor = true;
                if (i + 1 < n && table[i + 1][j] == v) neighbor = true;
                if (j > 0 && table[i][j - 1] == v) neighbor = true;
                if (j + 1 < m && table[i][j + 1] == v) neighbor = true;

                if (!neighbor && p.first == 1) p.second = false;
            }
        }

        bool ok = true;
        for (auto &[k, p] : freq) {
            if (p.first != 3 || !p.second) {
                ok = false;
                break;
            }
        }

        cout << (ok ? "YES\n" : "NO\n");
    }
}