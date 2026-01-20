// Author: H. Hristov
#pragma GCC optimize("Ofast,fast-math")
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    auto min3 = [](int a, int b, int c) {
        int min1 = min(a, b);
        int min2 = min(min1, c);
        return min2;
    };
    
    short n, m;
    cin >> n >> m;
    vector<vector<short>> a(n, vector<short>(m));
    vector<vector<int>> dp(n, vector<int>(m));
    for(int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) cin >> a[i][j];

    for(int i = 0; i < n; ++i) dp[i][0] = a[i][0];
    for(int j = 1; j < m; ++j) {
        for (int i = 0; i < n; ++i) {
            if (i > 0 && i < n - 1)
                dp[i][j] = min3(dp[i - 1][j - 1], dp[i][j - 1], dp[i + 1][j - 1]) + a[i][j];
            else if (i == 0)
                dp[i][j] = min(dp[i][j - 1], dp[i + 1][j - 1]) + a[i][j];
            else if (i == n - 1)
                dp[i][j] = min(dp[i - 1][j - 1], dp[i][j - 1]) + a[i][j];
        }
    }

    int res = dp[0][m - 1];
    for(int i = 1; i < n; ++i)
        if (dp[i][m - 1] < res) res = dp[i][m - 1];
    cout << res;
    return 0;
} // dp
