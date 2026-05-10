// RSOP XXXVIII > B
// Author: H. Hristov
#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>

#define FOR(i, a, b) for(int i = (a); i <= (b); ++i)
using ll = long long;
using ull = unsigned long long;

using namespace std;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        ull dp[2][5] = {};
        dp[0][1] = 1;
        dp[0][0] = 1;

        FOR(i, 2, n) {
            FOR(j, 2, 4) dp[1][j] = dp[0][j - 1];
            dp[1][1] = ((dp[0][2] + dp[0][3]) << 1);
            dp[1][0] = dp[0][0] + dp[1][1] - dp[0][4];

            FOR(j, 0, 4) dp[0][j] = dp[1][j];
        }

        cout << dp[0][0] << '\n';
    }
}