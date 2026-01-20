// Author: H. Hristov
#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll dp[43][43][22];

int main() {
    short tk, ti, tj;
    cin >> tk >> ti >> tj;
    ti = abs(ti); tj = abs(tj);

    if ((tk & 1) && ((ti + tj) & 1) == 0) { cout << 0; return 0; }
    if ((tk & 1) == 0 && (ti + tj) & 1) { cout << 0; return 0; }

    dp[ti + 21][tj + 21][0] = 1;

    for(int l = 1; l <= tk; ++l) {
        for(int i = 0; i < 43; ++i) {
            for(int j = 0; j < 43; ++j) {
                if (i > 0)  dp[i][j][l] += dp[i-1][j][l-1];
                if (i < 42) dp[i][j][l] += dp[i+1][j][l-1];
                if (j > 0)  dp[i][j][l] += dp[i][j-1][l-1];
                if (j < 42) dp[i][j][l] += dp[i][j+1][l-1];
            }
        }
    }

    cout << dp[21][21][tk];
    return 0;
}

// #pragma GCC optimize("Ofast,unroll-loops")
// #include <bits/stdc++.h>
// #define ll unsigned long long
// using namespace std;

// int main() {
//     short k, n, m;
//     cin >> k >> n >> m;
//     if ((k & 1) && ((n + m) & 1)==0) cout << 0;
//     else if ((k & 1) == 0 && ((n + m) & 1)) cout << 0;
//     else {
//         // cout << "solvable\n";
//         vector<vector<ll>> dp(k + 1, vector<ll>(k + 1));
//         vector<vector<ll>> dpComb(k + 1);
//         dpComb[0] = vector<ll>(1, 1);
//         for(int i = 1; i <= k; ++i) {
//             dpComb[i] = vector<ll>(i + 1);
//             dpComb[i][0] = 1;
//             for (int j = 1; j < i; ++j) {
//                 dpComb[i][j] = dpComb[i-1][j] + dpComb[i-1][j-1];
//             }
//             dpComb[i][i] = 1;
//         }

//         for(int i = 0; i <= k; ++i) dp[i][k - i] = dpComb[k][i];
//         int q = 1;
//         for(int i = k - 2; i >= ((k & 1) ? 1 : 0); i -= 2, ++q) {
//             for(int j = 0; j <= i; ++j) {
//                 dp[j][i - j] = dp[j + 1][i - j + 1] * dp[k - q][q];
//             }
//         }
//         cout << dp[abs(n)][abs(m)];
//     }
// }