// Author: H. Hristov
#pragma GCC optimize("O3,unroll-loops,Ofast,avx2,fast-math")
#include <bits/stdc++.h>
#define ll long long

const ll MOD = 10e8 + 7;
using namespace std;

int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    short n;
    int l, r;
    cin >> n >> l >> r;
    vector<vector<int>> dp(n + 1, vector<int>(r + 1, 0));
    for (int i = 1; i <= n; ++i) {
        dp[i][0] = 1;
        for (int j = 1; j <= r; ++j) {
            for (int k = 0; k < i; ++k)
            {
                if (j >= k)
                    dp[i][j] = (dp[i][j] + dp[i - 1][j - k]) % MOD;
            }
        }
    }
    ll res = 0;
    while(l <= r) 
        res = (res + dp[n][l++]) % MOD;

    cout << res;
}
// Prefix array and optimize by memory but I am too stupid for this.