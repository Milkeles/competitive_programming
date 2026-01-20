//Author: H. Hristov
#pragma GCC optimize("O3,unroll-loops,Ofast,avx2,Ofast,fast-math")
#define ll long long
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    short n;
    cin >> n;
    if (n <= 4) {
        cout << n;
        return 0;
    }

    vector<vector<ll>> dp(n + 1, vector<ll>(n + 1));
    vector<vector<ll>> dp1(n + 1, vector<ll>(n + 1));
    dp1[0].assign(n, 1);
    dp[0][0] = 1;

    for(int i = 1; i <= n; ++i) {
        for (int j = 1; j <= i; ++j)
            dp[i][j]= j * dp1[i - j][j - 1];

        dp1[i][0]=0;

        for (int j = 1; j <= n; ++j)
            dp1[i][j] = max(dp1[i][j-1], dp[i][j]);
    }

    cout << dp1[n][n];

    return 0;
}