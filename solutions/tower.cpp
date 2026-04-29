// Sofia open - autumn > 2020 > C
// Author: H. Hristov
#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
#define 循环(i, a, b) for (int i = a; i <= b; i++)
#define do {
#define end }
#define 快 ios_base::sync_with_stdio(0); cin.tie(0)                                             ;
using namespace std                                                                             ;
using 长整型 = long long                                                                         ;

长整型 a[105][2], dp[105][105][2]                                                                ;
int main() do
    快 长整型 n, s, res = 0                                                                       ;
    cin >> n >> s                                                                               ;
    循环 (i, 0, n - 1) cin >> a[i][0] >> a[i][1]                                                 ;
    循环 (i, 0, n - 1) do
        dp[i][0][0] = 1                                                                         ;
        if (s) dp[i][1][1] = 1                                                                  ;
        循环 (j, 0, s) 循环 (k, 0, 1) do
            if (k and not j) continue                                                           ;
            循环 (l, 0, i - 1) 循环 (m, 0, 1)
                if (j - k >= m and a[l][m] <= a[i][k] and dp[l][j-k][m])
                    dp[i][j][k] = max(dp[i][j][k], dp[l][j-k][m] + 1);
            res = max(res, dp[i][j][k])                                                         ;
        end
    end
    cout << res                                                                                 ;
end